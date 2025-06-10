package create;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;

import utils.Block;
import utils.Page;

/**
 * 该类建立数据库目录及默认名称的日志文件
 * 目前用不到了。。。
 * @author 卅TAT
 *
 */
public class DBAndLog {
	
	private int BLOCK_SIZE = 512;//指定磁盘块映射大小
	
	private int BUFFER_NUM = 6; //指定缓冲区的数目
	
	private String FilePath = "E:\\Java\\database"; //数据库主路径
	
	private String DBDir; //待指定的数据库文件目录名称
	
	private String LogName;  //日志文件名
	
	private FileMgr f1; //文件类对象 
	

	public DBAndLog(String dirname, int blksize) {
		this.DBDir = FilePath +"\\" +dirname; //数据库文件目录
		f1 = new FileMgr(DBDir,blksize); //建立数据库目录
		createLog();//建立默认文件名的日志文件
	}
	public String getLOG_NAME() {
		return LogName;
	}

	//得到文件对象
	public FileMgr gFile() {
		return f1;
	}
	
	//创建日志文件
	private void createLog() {
		//日志文件名
		String Uuid = UUID.randomUUID().toString().split("-")[4];
		Date day=new Date();    
		SimpleDateFormat df = new SimpleDateFormat("yyyyMMdd"); 
		SimpleDateFormat df1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss"); 
		this.LogName = df.format(day)+Uuid;
		String logPath = "\\logs\\"+LogName;
		
		//写入的起始位置
		int startpos = 0; 
		int npos = startpos + Page.maxLength(df1.format(day).length()); //logPath的结束位置
		
		byte[] b = new byte[npos + 2 * Integer.BYTES];//记录的总长度，4字节是整数长度
		
		// 字节数组b,是内存页的实际存储空间
		Page p = new Page(b); //按照记录长度（即，字节数组）建立内存页
		Block blk = new Block(logPath,0); //建立块 
		p.setString(startpos, df1.format(day));//把该条记录的字符串按位置startpos写入内存页
		f1.write(blk,p);
		logPath = " " + blk.getBlockID();
		p.setString(npos + Integer.BYTES - 2, logPath);
		f1.write(blk,p);
	}
}
