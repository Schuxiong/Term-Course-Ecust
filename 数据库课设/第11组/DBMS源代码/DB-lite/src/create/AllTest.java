package create;

import bean.StatementType;
import sql.InsertStatement;
import sql.SelectStatement;
import utils.SchemaInfo;
import utils.User;

public class AllTest {
	public static void main(String[] args) {
		User u1 = new User();
		u1.setUser("emmm");
		u1.setUseDB("111");
		u1.setSelect(true);
		u1.setCreate(true);
		u1.setDelete(true);
		u1.setInsert(true);
		u1 = new StatementType().getStatementType("create database 111", u1);
		System.out.println(u1.getLogs());
		u1 = new StatementType().getStatementType("use 111", u1);
		
		System.out.println(u1.getLogFileName());
		new StatementType().getStatementType("create table stu1 (" + 
				"	sname String(9)," + 
				"	age int(4)," + 
				"	class String(4)," + 
				"	grade double(8));	", u1);  
		//中文字符占3，英文数字占1，字符串偏移量+4！  (9)代表的是最长三个中文字符
		System.out.println(u1.getLogs());
		
		SchemaInfo sf = new SchemaInfo("D:\\Code_Java\\database\\test\\schema.dbs", "stu");
		String[][] info = sf.getInfo();
		System.out.println(info[1][0]);
		
		System.out.println(u1.getUseDB());
		System.out.println(sf.getFieldNum());
		System.out.println(sf.getTableID());
		
//		u1 = new InsertStatement().processInsert("Insert INTO t_student (sno,sname,age,class,phone,grade)"
//				+ " values ('20200001','张同学',18,'2020','13181111111',85.9);", u1);
		u1 = new InsertStatement().processInsert("Insert INTO stu1 (sname,age,class,grade)"
				+ " values ('张11',16,'2019',95);", u1);
		u1 = new InsertStatement().processInsert("Insert INTO stu1 (sname,age,class,grade)"
				+ " values ('张12',17,'2018',90);", u1);
		u1 = new InsertStatement().processInsert("Insert INTO stu1 (sname,age,class,grade)"
				+ " values ('张13',19,'2018',80);", u1);
		u1 = new InsertStatement().processInsert("Insert INTO stu1 (sname,age,class,grade)"
				+ " values ('张14',19,'2017',70);", u1);
		u1 = new InsertStatement().processInsert("Insert INTO stu1 (sname,age,class,grade)"
				+ " values ('张15',18,'2020',66);", u1);
//		System.out.println(u1.getLogs());
		u1 = new SelectStatement().processSelect("select * from stu1", u1);
		System.out.println(u1.getSelectResult());
	}
}
