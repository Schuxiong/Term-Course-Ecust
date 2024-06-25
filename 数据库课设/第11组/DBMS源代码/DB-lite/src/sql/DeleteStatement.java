package sql;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

import bean.WhereType;
import create.TableRead;
import utils.RandomAccessFileRW;
import utils.Table;
import utils.User;

/**
 * 按照条件删除表--> 本质上是将表的flag置为false DELETE FROM project WHERE id>11
 * 
 * @author 卅TAT
 */
public class DeleteStatement {
	private String FilePath = "E:\\Java\\database"; // 数据库主路径

	public User processInsert(String statement, User u1) {

		String state = statement.toLowerCase().replace(";", "");
		String[] where = state.split("where");
		String tbName = null;
		// 获取tbName 表名 where[0]:DELETE FROM project
		if (where[0].split("from").length > 1) {
			tbName = where[0].split("from")[1].trim();
//			System.out.println(tbName);
		} else { 
			u1.setSelectResult("null");
			u1.setLogs("Error: 1064 - You have an error in your SQL syntax~logs:" + u1.toString()
					+ "     \n>>operation failure");
			return u1;
		}


		// 获取待删除的表的所有信息，key为字段名，value为该列数据，不同类型存在于不同map
		TableRead tableRead = new TableRead();
		Table fv = tableRead.getFV(tbName, u1);
		ArrayList<Integer> queryIndex = new WhereType().getType(statement, fv);// 下标从0开始
		System.out.println(queryIndex);

		// 开始删除（即修改）
		String filePath = FilePath + "\\" + u1.getUseDB() + "\\" + tbName + ".dbf";
		File f = new File(filePath);
		RandomAccessFile raf = null;
		try {
			raf = new RandomAccessFile(f, "rws");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		RandomAccessFileRW rafrw = new RandomAccessFileRW();
		// 将待删除表的flag置为false：根据下标的行数和偏移量确定位置，写文件
		// 每个修改位置为：queryIndex*128 ps：flag从每行的偏移量为0开始 info[字段名][类型][][偏移量]
		if (f.length() == 0) {
			u1.setLogs("Error：file is empty");
			return u1;
		}

		for (Integer integer : queryIndex) {
			try {
				rafrw.writeBooleanRAF(raf, integer*128, false);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try {
//			System.out.println(raf.length()+"----");
			raf.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		u1.setLogs("OK~Logs: " + u1.toString() + "  \n>>delete table " + tbName + " success");
		return u1;
	}
//测试删除一行数据
//	public static void main(String[] args) {
//		User u1 = new User();
//		u1.setLevel(1);
//		u1.setUseDB("hhh");
//		User u3 = new SelectStatement().processSelect("select * from stu1;", u1);
//		System.out.println(u3.getSelectResult());
////		u1 = new DeleteStatement().processInsert("delETe frOM stu1 where sname = '张15'", u1);
//		System.out.println(u1.getLogs());
//		User u2 = new SelectStatement().processSelect("select * from stu1;", u1);
//		
//		System.out.println(u2.getSelectResult());
//	}
}
