package sql;

import java.util.ArrayList;

import bean.WhereType;
import create.TableRead;
import utils.SchemaInfo;
import utils.Table;
import utils.User;

/**
 * 处理select语句,select * from 表名 where 条件
 * ①根据条件获取行号，条件：支持多余空格，支持字符串相等(根据输入有无')、数值大于、小与、等于 ②取 字段名
 * 对应的行号的内容，存成字符串-->u1.getResult 若语句不对，u1.setLogs(""Error: 1064 - You have an
 * error in your SQL syntax;"....
 * 
 * @author 卅TAT
 *
 */
//		select *|distinct 字段1,字段2,…… 表达式 from 表名称[where 条件]
//	    select * from 表名 where 条件    （ps：flag == true）若为管理员，全显示

public class SelectStatement {

	private String FilePath = "E:\\Java\\database"; // 数据库主路径

	public User processSelect(String statement, User u1) {

		String state = statement.toLowerCase().replace(";", "");
		String[] where = state.split("where");
		String tbName = null;
		// 获取tbName 表名
		if (where[0].split("from").length > 1) {
			tbName = where[0].split("from")[1].trim();
//			System.out.println(tbName);
		} else {
			u1.setSelectResult("null");
			u1.setLogs("Error: 1064 - You have an error in your SQL syntax~logs:" + u1.toString()
					+ "     \n>>operation failure");
			return u1;
		}

		// 获取fieldName 字段名列表
		SchemaInfo inf = new SchemaInfo(FilePath + "\\" + u1.getUseDB() + "\\schema.dbs", tbName);
		inf.getInfo();
		String[] fieldName = inf.getFieldName();// 一定要放在getInfo之下！

		// 获取表内所有信息，key为字段名，value为该列数据，不同类型存在于不同map
		TableRead tableRead = new TableRead();
		Table fv = tableRead.getFV(tbName, u1);
		ArrayList<Integer> queryIndex = new WhereType().getType(statement, fv);
//		System.out.println("结果如下：" + queryIndex.toString());

		// 如果表文件长度为 0 或者 待查询下标为空
		if (tableRead.getFileLength() == 0 || queryIndex == null) {
			u1.setSelectResult("null");
			u1.setLogs("Warning: The content is empty~logs:" + u1.toString() + "     \n>>operation failure");
			return u1;
		}

		// queryIndex 存放所有下标（未区分flag）
//		for (Entry<String, ArrayList<String>> entry : fv.getTblFVString().entrySet()) {
//			System.out.println(entry.getKey() + " ： " + entry.getValue());
//		}
//
//		for (Entry<String, ArrayList<Double>> entry : fv.getTblFVDouble().entrySet()) {
//			System.out.println(entry.getKey() + " ： " + entry.getValue());
//		}

		// 处理，将flag为true的行记录！（分管理员和非管理员）
		if (u1.getLevel() == 0) {// 非管理员，将flag为true的行输出
			ArrayList<Boolean> flagColumnValue = fv.getTblFVBoolean().get("flag");
			if (flagColumnValue != null) {
				for (int i = 0; i < flagColumnValue.size(); i++) {
					if (!flagColumnValue.get(i)) { // 如果第i行是false，就移除queryIndex中值为i的元素
						queryIndex.remove(Integer.valueOf(i));
					}
				}
			}
		}

		String findField = state.replace("select", "").split("from")[0];
		String[] fd = findField.split(",");
		String[] find = null;
		String head = "";

		if ("*".equals(fd[0].trim())) {
			if (u1.getLevel() == 1) {
				find = new String[fieldName.length];
				for (int i = 0; i < fieldName.length; i++) {
					find[i] = fieldName[i].trim();
					head += find[i] + "\t";
				}
			} else {// 查所有(不包括flag列）
				find = new String[fieldName.length];
				for (int i = 1; i < fieldName.length; i++) {
					find[i - 1] = fieldName[i].trim();
					head += find[i - 1] + "\t";
				}
			}
		} else {
			if (u1.getLevel() == 1) {
				find = new String[fd.length];
				for (int i = 0; i < fd.length; i++) {
					find[i] = fd[i].trim();
					head += find[i] + "\t";
				}
			} else {
				find = new String[fd.length];
				for (int i = 1; i < fd.length; i++) {
					find[i-1] = fd[i].trim();
					head += find[i-1] + "\t";
				}
			}
		}

		String line = head + "\n";
//		System.out.println(queryIndex.toString());
		for (int queryLine : queryIndex) {
			for (int i = 0; i < find.length; i++) {
				if (fv.getTblFVString().get(find[i]) != null) {
					line += fv.getTblFVString().get(find[i]).get(queryLine) + "\t";
				} else if (fv.getTblFVBoolean().get(find[i]) != null) {
					line += fv.getTblFVBoolean().get(find[i]).get(queryLine) + "\t";
				} else if (fv.getTblFVInt().get(find[i]) != null) {
					line += fv.getTblFVInt().get(find[i]).get(queryLine) + "\t";
				} else if (fv.getTblFVChar().get(find[i]) != null) {
					line += fv.getTblFVChar().get(find[i]).get(queryLine) + "\t";
				} else if (fv.getTblFVDouble().get(find[i]) != null) {
					line += fv.getTblFVDouble().get(find[i]).get(queryLine) + "\t";
				} else {
				}
			}
			line += "\n";
		}
//		System.out.println(line);

		u1.setSelectResult(line);// 将查询结果存入u1,方便获取
		u1.setLogs("OK~Logs: " + u1.toString() + "    \n>>select " + tbName + " success");
		return u1;
	}

//	测试选择
	public static void main(String[] args) {
		User u1 = new User();
		u1.setUseDB("111");
		u1.setLevel(0);
		User u2 = new SelectStatement().processSelect("select * from stu1;", u1);
		System.out.println(u2.getSelectResult());
	}
}
