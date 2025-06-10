package bean;

public enum Type {
	//数据定义语言，包括：create、alter、drop
	DDL_CREATE, DDL_ALTER, DDL_DROP,
	//数据操纵语言，包括：select、insert、update、delete
	DML_SELECT, DML_INSERT, DML_UPDATE, DML_DELETE,
	//数据控制语言，包括：grant、deny、revoke
	DCL_GRANT, DCL_DENY, DCL_REVOKE,
	//事务控制语言，包括:commit、rollback、savepoint。
	TC_COMMIT, TC_ROLLBACK, TC_SAVEPOINT, 
	//暂不支持~
	Other,
}
