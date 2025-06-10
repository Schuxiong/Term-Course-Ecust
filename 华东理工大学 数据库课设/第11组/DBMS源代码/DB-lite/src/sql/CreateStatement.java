package sql;

import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;

import create.FileMgr;
import utils.Block;
import utils.Page;
import utils.SchemaWriteIn;
import utils.User;
/**
 * 可使用库（同时创建日志）、创建库、创建表
 * 创建并写入日志，然后关闭日志文件，日志名在u1.setLogFileName
 * @author 卅TAT
 *
 */
public class CreateStatement {

	private String FilePath = "E:\\Java\\database"; // 数据库主路径

	// 成功Statement ：use xxx create database xxx create table xxx
	public CreateStatement() {
	}

	// 返回字符串有：Error、FileName、FLogName
	// Error: error~log
	// FileName:
	// FLogName: logPath+LogName+"_"+blk.getBlockID()~log
	public User processCreate(String statement, User u1) {
		statement = statement.replace(";",""); 
		String state = statement.toLowerCase().replace("[ ]+", " ");
		String[] split = state.replace("(", " ").split(" "); // 替换左括号，防止出现tablename后无空格

		if ("use".equals(split[0])) {
			// 进入这个数据库，对表进行增删改查
			String DBDir = FilePath + "\\" + split[1]; // 数据库文件目录
			File dbDirFile = new java.io.File(DBDir);
			if (!dbDirFile.exists()) { // 不存在就报错
				String log = "Error:1049 - Unknown database \'" + split[1] + "\'" + "~Logs: " + u1.toString()
						+ "  \n>>use database " + split[1] + " failure";
				u1.setLogs(log);
				return u1;
			} else { // 存在 就进入这个数据库并获取数据库目录的文件柄 和 日志目录的文件柄
				File logDir = new java.io.File(DBDir + "\\logs");
				if (!logDir.exists()) {
					logDir.mkdir();
				}
				// 日志文件名
				String Uuid = UUID.randomUUID().toString().split("-")[4];
				Date day = new Date();
				SimpleDateFormat df = new SimpleDateFormat("yyyyMMdd");
				SimpleDateFormat df1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
				String LogName = df.format(day) + Uuid + ".log";
				String logPath = DBDir + "\\logs";
				File logFile = new File(logPath+"\\"+LogName);
				try {
					logFile.createNewFile();
				} catch (IOException e1) {
					e1.printStackTrace();
				}
				int startpos = 0;
				int npos = startpos + Page.maxLength(df1.format(day).length()); // logPath的结束位置
				byte[] b = new byte[npos * 2];// 记录的总长度，4字节是整数长度
				FileMgr fLog = new FileMgr(logPath+"\\"+LogName, 512);
				// 字节数组b,是内存页的实际存储空间
				Page p = new Page(b); // 按照记录长度（即，字节数组）建立内存页
				Block blk = new Block("\\logs"+"\\"+LogName, 0); // 建立块
				p.setString(startpos, df1.format(day));// 把该条记录的字符串按位置startpos写入内存页
				fLog.write(blk, p);
//				System.out.println(fLog.getF());
				p.setString(npos, "use this database");
				fLog.write(blk, p);
				try {
					fLog.getF().close();
				} catch (IOException e) {
					e.printStackTrace();
				}
				u1.setUseDB(split[1]);// 重要！若useDB不为空，说明使用该数据库，此时有路径，可找到库中文件！
				u1.setLogFileName(LogName);
				u1.setLogs("OK~Logs:" + u1.toString() + "    \n>>use database " + split[1] + " success");
				return u1;
			}
		} else {// create
			if ("database".equals(split[1])) {
				// 创建一个数据库
				String DBDir = FilePath + "\\" + split[2]; // 数据库文件目录
				File dbDirFile = new java.io.File(DBDir);
				if (dbDirFile.exists()) {
					// 如果数据库存在，报错
					u1.setLogs("Error:1007 - Can't create database \'" + split[2] + "\'; database exists" + "~Logs: "
							+ u1.toString() + "    \n>>create database " + split[2] + " failure");
					return u1;
				} else {
					// 如果数据库不存在，创建并写入log
					dbDirFile.mkdir(); // 建立目录文件夹
					u1.setLogs("OK~Logs: " + u1.toString() + "	\n>>create database " + split[2] + " success");
					return u1;
				}
			} else if ("table".equals(split[1])) {
				if (u1.getUseDB() != null) {
					String tableName = split[2];
					String[][] nameAttrLen = getNameAndAttr(statement);// 拆解句子
					// 创建一个表
					String DBDir = FilePath + "\\" + u1.getUseDB() + "\\" + tableName + ".dbf"; // 文件路径
					String schema = FilePath + "\\" + u1.getUseDB() + "\\schema.dbs";
					
					File dbDirFile = new java.io.File(DBDir);
					if (!dbDirFile.exists()) {// 不存在，创建！
						try {
							dbDirFile.createNewFile();
						} catch (IOException e) {
							e.printStackTrace();
						}
						new SchemaWriteIn(schema, tableName, nameAttrLen); //创建模式表
						u1.setLogs("OK~Logs:"+ u1.toString() + "create table " + split[2] + " success");
						return u1;// !!!!!!!!!!!!!
					} else {// 存在，报错
						u1.setLogs("Error:1050 - Table '"+split[2]+"' already exists~Logs: " + u1.toString()
								+ "    \n>>create table " + split[2] + " failure");
						return u1;
					}
					// 表已经存在：
				} else {
					u1.setLogs("Error: Unselected database~logs: " + u1.toString() + "    \n>>create table " + split[2]
							+ " failure");
					return u1;
				}
			} else {
				u1.setLogs("Error: 1064 - You have an error in your SQL syntax~logs:" + u1.toString()+"     \n>>operation failure");
				return u1;
			}
		}

	}// end (String)processCreate 

	private String[][] getNameAndAttr(String str) {
		str = str.toLowerCase();
		str = str.replace("\t", " ");
		str = str.replaceAll("[ ]+", " ");
		String[] row = str.split(",");// 用,拆分
		String[][] all = new String[row.length][3];
		for (int i = 0; i < row.length; i++) {
			row[i] = row[i].trim(); // 去除首尾空格
			String[] spl = row[i].split(" ");
			String attr = spl[spl.length - 1].replace(")", "").replace(";", "");
			String[] attLen = attr.split("\\(");
			if (i == 0) {// 假设：必有一列id
				all[i][0] = spl[spl.length - 2];
			} else {
				all[i][0] = spl[0];
			}
			all[i][1] = attLen[0];
			all[i][2] = attLen[1];
		}
		return all;
		/*
		 * sno String 8 
		 * name String 15 
		 * age int 4 
		 * class String 4 
		 * phone String 11 
		 * grade double 8
		 */
	}
}
