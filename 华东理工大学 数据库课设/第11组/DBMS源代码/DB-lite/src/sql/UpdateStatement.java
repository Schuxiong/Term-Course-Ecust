package sql;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

import bean.DataType;
import bean.WhereType;
import create.TableRead;
import utils.RandomAccessFileRW;
import utils.SchemaInfo;
import utils.Table;
import utils.User;

/**
 * 按照条件更新表某行某列数据 UPDATE stu1 SET class='2000' WHERE grade > 75
 * 
 * @author 卅TAT
 */
public class UpdateStatement {
	private String FilePath = "E:\\Java\\database"; // 数据库主路径
 
	public User processUpdate(String statement, User u1) {

		// 1.处理输入的sql语句
		String state = statement.toLowerCase().replace(";", "");
		String[] where = state.split("where");
		String tbName = null;

		// 1.1获取tbName 表名 where[0]:DELETE FROM project
		if (where[0].split("set").length > 1) {
			tbName = where[0].split("set")[0].replace("update", "").trim();
//			System.out.println("表名"+tbName);
		} else {
			u1.setSelectResult("null");
			u1.setLogs("Error: 1064 - You have an error in your SQL syntax~logs:" + u1.toString()
					+ "     \n>>operation failure");
			return u1;
		}

		// 1.2获取k、v
		String setK = where[0].split("set")[1].split("=")[0].trim();
		String setV = where[0].split("set")[1].split("=")[1].trim();
		setV = setV.replace("'", "").replace("\"", "");
//		System.out.println(setK + "------" + setV);

		// 2. 找到该字段的整体偏移量，并根据类型重新赋值
		// 2.1 从模式表中 获取fieldName 字段名列表
		SchemaInfo inf = new SchemaInfo(FilePath + "\\" + u1.getUseDB() + "\\schema.dbs", tbName);
		String[][] info = inf.getInfo();// 模式表存的所有信息，字段名、类型、长度、偏移量

		// 2.2获取待删除的表tbName的所有信息，key为字段名，value为该列数据，不同类型存在于不同map
		TableRead tableRead = new TableRead();
		Table fv = tableRead.getFV(tbName, u1);
		// 2.3获取待修改的行号
		ArrayList<Integer> queryIndex = new WhereType().getType(statement, fv);// 下标从0开始
//		System.out.println("待修改的行号："+queryIndex.toString());

		// 3.开始修改
		// 3.1 获取k的属性：类型+偏移量
		String type = null;
		String offset = null;
		for (String[] ifo : info) {
			if (setK.equals(ifo[0])) {
				type = ifo[1];
				offset = ifo[3];
//				System.out.println("单个偏移量"+offset);
//				System.out.println("type:" + type);
			}
		}

		// 3.2 写入文件
		String filePath = FilePath + "\\" + u1.getUseDB() + "\\" + tbName + ".dbf";
		File f = new File(filePath);
		RandomAccessFile raf = null;
		try {
			raf = new RandomAccessFile(f, "rws");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		RandomAccessFileRW rafrw = new RandomAccessFileRW();

		//先判断一下文件是否为空
		if (f.length() == 0) {
			u1.setLogs("Error：file is empty");
			return u1;
		}

		type = new DataType().getDataType(type);
		int offsetInt = Integer.valueOf(offset);
		for (int i = 0; i < queryIndex.size(); i++) {
//			System.out.println(type);
			if ("Int".equals(type)) {
				try {
					rafrw.writeIntRAF(raf, queryIndex.get(i)*128 + offsetInt, Integer.valueOf(setV));
				} catch (IOException e) {
					e.printStackTrace();
				}
			} else if ("Char".equals(type)) {
				try {
					rafrw.writeStringRAF(raf, queryIndex.get(i)*128 + offsetInt, setV);
				} catch (IOException e) {
					e.printStackTrace();
				}

			} else if ("String".equals(type)) {
				try {
					rafrw.writeStringRAF(raf,queryIndex.get(i)*128 + offsetInt, setV);
				} catch (IOException e) {
					e.printStackTrace();
				}
			} else if ("Double".equals(type)) {
				Double dbIn = Double.valueOf(setV);
				try {
					rafrw.writeDoubleRAF(raf,queryIndex.get(i)*128+ offsetInt, dbIn);
				} catch (IOException e) {
					e.printStackTrace();
				}

			} else if ("Boolean".equals(type)) {
				Boolean blIn = Boolean.valueOf(setV);
				try {
					rafrw.writeBooleanRAF(raf,queryIndex.get(i)*128 + offsetInt, blIn);
				} catch (IOException e) {
					e.printStackTrace();
				}

			} else {
				u1.setLogs("Error：Unknowable error");
				return u1;
			}
		}

			try {
				raf.close();
			} catch (IOException e) {
				e.printStackTrace();
			}

			u1.setLogs("OK~Logs: " + u1.toString() + "  \n>>update table " + tbName + " success");
			return u1;
	}

	public static void main(String[] args) {
		User u1 = new User();
		u1.setLevel(1);
		u1.setUseDB("0609");
		User u3 = new UpdateStatement().processUpdate("UPDATE stu1 SET class = '2000' WHERE grade > 75;", u1);
//		System.out.println(u3.getSelectResult());
////		u1 = new DeleteStatement().processInsert("delETe frOM stu1 where sname = '张15'", u1);
//		System.out.println(u1.getLogs());
		User u2 = new SelectStatement().processSelect("select * from stu1;", u1);
		System.out.println(u2.getSelectResult());
	}
}
