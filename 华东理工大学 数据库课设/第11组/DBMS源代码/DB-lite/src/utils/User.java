package utils;

public class User {
	private String user;
	private String password;
	private int level;
	private boolean Insert;
	private boolean Update;
	private boolean Delete;
	private boolean Select;
	private boolean Create;
	private String useDB;
	private String logs;
	private String logFileName;
	private String selectResult;

	
	public String getSelectResult() {
		return selectResult;
	}

	public void setSelectResult(String selectResult) {
		this.selectResult = selectResult;
	}

	public String getLogFileName() {
		return logFileName;
	}

	public void setLogFileName(String logFileName) {
		this.logFileName = logFileName;
	}

	public String getLogs() {
		return logs;
	}

	public void setLogs(String logs) {
		this.logs = logs;
	}

	public boolean isInsert() {
		return Insert;
	}

	public void setInsert(boolean insert) {
		Insert = insert;
	}

	public boolean isUpdate() {
		return Update;
	}

	public void setUpdate(boolean update) {
		Update = update;
	}

	public boolean isDelete() {
		return Delete;
	}

	public void setDelete(boolean delete) {
		Delete = delete;
	}

	public boolean isSelect() {
		return Select;
	}

	public void setSelect(boolean select) {
		Select = select;
	}

	public boolean isCreate() {
		return Create;
	}

	public void setCreate(boolean create) {
		Create = create;
	}

	public User() {
	}

	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public int getLevel() {
		return level;
	}

	public void setLevel(int level) {
		this.level = level;
	}
	
	public String getUseDB() {
		return useDB;
	}

	public void setUseDB(String useDB) {
		this.useDB = useDB;
	}

	@Override
	public String toString() {
		if (this.level == 1) {
			return user + "(管理员)	权限-all";
		}

		String permission = "";
		if(Create)    permission +="Create  ";
		if(Insert)    permission +="Insert  ";
		if(Delete)    permission +="Delete  ";
		if(Update)    permission +="Update  ";
		if(Select)    permission +="Select  ";
		return  user +"(普通用户)	权限: "+permission;
	}

}
