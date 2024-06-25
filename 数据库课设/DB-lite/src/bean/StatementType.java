package bean;

import sql.CreateStatement;
import sql.DeleteStatement;
import sql.InsertStatement;
import sql.SelectStatement;
import sql.UpdateStatement;
import utils.User;

/**
 * 处理输入语句，“完全符合”规范的继续处理，否则返回Type.Other， 表示不能识别！可能原因：未开发功能或语法有误！
 * 
 * @author 卅TAT
 *
 */
public class StatementType {

	public User getStatementType(String statement, User u1) {
		String state = statement.toLowerCase();
		state = state.replace("[ ]+", " "); 
		String[] split = state.split(" ");

		if ("create".equals(split[0])) {  //处理create语句
			if (!u1.isCreate()) {
				u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser() + "'@'localhost' to Create~"
						+ "Logs:" + u1.toString() + "    \n>>create success");
				return u1;
			}
			User u2 = new CreateStatement().processCreate(statement, u1);
			return u2;
//			return Type.DML_SELECT;
		} else if ("use".equals(split[0])) {
			if (!u1.isCreate()) {
				u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser() + "'@'localhost' to Create"
						+ "~Logs:" + u1.toString() + "    \n>>use success");
				return u1;
			}
			User u2 = new CreateStatement().processCreate(statement, u1);
			return u2;
//			return Type.DML_SELECT;
		} else if ("select".equals(split[0])) {
			if (u1.getUseDB() != null) {
				if (!u1.isSelect()) {
					u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser() + "'@'localhost' to Select"
							+ "~Logs:" + u1.toString() + "    \n>>select failue");
					return u1;
				}
				User u2 = new SelectStatement().processSelect(statement, u1);
				return u2;
			} else {
				u1.setLogs("Error:1049 - Unknown database null" + "~Logs: " + u1.toString()
						+ "  \n>>use database null failure");
				return u1;
			}

//			return Type.DML_SELECT;
		} else if ("insert".equals(split[0]) && "into".equals(split[1])) {
			if (u1.getUseDB() != null) {
				if (!u1.isInsert()) {
					u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser() + "'@'localhost' to Insert"
							+ "~Logs:" + u1.toString() + "    \n>>insert failure");
					return u1;
				}
				User u2 = new InsertStatement().processInsert(statement, u1);
				return u2;
			} else {
				u1.setLogs("Error:1049 - Unknown database null" + "~Logs: " + u1.toString()
						+ "  \n>>use database null failure");
				return u1;
			}
//			return Type.DML_INSERT;
		} else if ("update".equals(split[0])) {
			if (u1.getUseDB() != null) {
				if (!u1.isUpdate()) {
					u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser() + "'@'localhost' to Update"
							+ "~Logs:" + u1.toString() + "    \n>>update failure");
					return u1;
				}
				User u2 = new UpdateStatement().processUpdate(statement, u1);
				return u2;
				
				
			} else {
				u1.setLogs("Error:1049 - Unknown database null" + "~Logs: " + u1.toString()
						+ "  \n>>use database null failure");
				return u1;
			}

//			return Type.DML_UPDATE;
		} else if ("delete".equals(split[0])) {
			if (u1.getUseDB() != null) {
				if (!u1.isDelete()) {
					u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser() + "'@'localhost' to Delete"
							+ "~Logs:" + u1.toString() + "    \n>>delete failure");
					return u1;
				}
				User u2 = new DeleteStatement().processInsert(statement, u1);
				return u2;	
			
			} else {
				u1.setLogs("Error:1049 - Unknown database null" + "~Logs: " + u1.toString()
						+ "  \n>>use database null failure");
				return u1;
			}
//			return Type.DML_DELETE;
		} else {
//			return Type.Other;//不能识别！可能原因：未开发功能或语法有误！
			u1.setLogs("Error:  1044 - Access denied for user '" + u1.getUser()
					+ "'@'localhost' to use iDB\n Try running it after modification" + "~Logs:" + u1.toString() + "    \n>>use iDB failure");
			return u1;
		}
	}
}
