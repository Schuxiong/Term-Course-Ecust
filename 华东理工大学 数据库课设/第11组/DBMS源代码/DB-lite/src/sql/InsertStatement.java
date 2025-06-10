package sql;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Arrays;
import java.util.HashMap;

import bean.DataType;
import utils.RandomAccessFileRW;
import utils.SchemaInfo;
import utils.User;

/**
 * 处理insert语句，一次只能插入一条！无数据置为0、"" 插入后关闭RandomAccessFile
 * 
 * @author 卅TAT
 *
 */

//		INSERT INTO 表名称(字段) values(数据)；  INSERT INTO student(id,NAME) VALUES(1,'学生1');
//		INSERT INTO 表名称(字段1，字段2，字段3) values(数据1，数据2，数据3)，(数据1，数据2，数据3)；
public class InsertStatement {
 
	private String FilePath = "E:\\Java\\database"; // 数据库主路径

	public User processInsert(String statement, User u1) {

		String state = statement.toLowerCase().replace("[ ]+", " ").replace(";", "");// 小写+?空格去重?
		String[] split = state.split("values"); // 0 是前，1是后，每字段数据
		String[] head = split[0].split(" ");
		String tableName = head[2];
		String field = head[3];
		String value = split[1];

		// 域名存在的可以插入数据，其他的置为默认值
		String[] fieldsIn = field.replace("(", "").replace(")", "").replace(" ", "").split(",");
		String[] valuesIn = value.replace("(", "").replace(")", "").replace(" ", "").split(",");

		HashMap<String, String> fvIn = new HashMap<>();

		for (int i = 0; i < fieldsIn.length; i++) {
			valuesIn[i] = valuesIn[i].replace("\'", "");//此处不之间区分数字/字符串，有机会在后边改
//			System.out.println(valuesIn[i]);
			fvIn.put(fieldsIn[i], valuesIn[i]);
		}
//		System.out.println(field);
//		System.out.println(value);

		if (u1.getUseDB() != null) {
			String filePath = FilePath + "\\" + u1.getUseDB() + "\\" + tableName + ".dbf";
			String schemaPath = FilePath + "\\" + u1.getUseDB() + "\\schema.dbs";
//			System.out.println(filePath);
			File f = new File(filePath);
			if (f.exists()) {
//				System.out.println("正在插入");
				// 表结构：域长度控制写入，每个字段信息控制写入，每条记录长度为：
				SchemaInfo info = new SchemaInfo(schemaPath, tableName);
//				System.out.println(info.getFieldNum()); 域数
				if (info.hasTable() == true) {
					String[][] allInfo = info.getInfo();
					String[] allfield = new String[info.getFieldNum()];
					for (int i = 0; i < allInfo.length; i++) {
						allfield[i] = allInfo[i][0];
					}
					// 先判断输入类型与字段类型是否一致 假设输入的类型都是对的，

					RandomAccessFile raf = null;
					try {
						raf = new RandomAccessFile(f, "rws");
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					}
					RandomAccessFileRW rafrw = new RandomAccessFileRW();
//					System.out.println(f.length());
					int startPos = 0;
					if (f.length() != 0) {
						int mul = (int) (f.length() / 128);
//						System.out.println(mul);
						startPos = (mul + 1) * 128;
//						System.out.println(startPos+"开始位置");
					}

//					System.out.println(info.getFieldNum());
					for (int i = 0; i < info.getFieldNum(); i++) {
//						System.out.println(allInfo[i][0]);
						boolean contains = Arrays.asList(fieldsIn).contains(allInfo[i][0]);
						String type = new DataType().getDataType(allInfo[i][1]);
//						System.out.println("数值类型：" + allInfo[i][1]);
//						System.out.println("实际类型： " + type);
						int offset = Integer.valueOf(allInfo[i][3])+startPos;
//						System.out.println(offset+"-===offset===");
						String In = fvIn.get(allInfo[i][0]);
//						System.out.println(In+"-----------");
						if ("Int".equals(type)) {
							if (contains) {
								// 如果存在新值，则根据值内容、类型、偏移量赋值
								try {
									rafrw.writeIntRAF(raf, offset, Integer.valueOf(In));
								} catch (IOException e) {
									e.printStackTrace();
								}
							} else {
								try {
									rafrw.writeIntRAF(raf, offset, 0);
								} catch (IOException e) {
									e.printStackTrace();
								}
							}
						} else if ("Char".equals(type)) {
							if (contains) {
								try {
									rafrw.writeStringRAF(raf, offset, In);
								} catch (IOException e) {
									e.printStackTrace();
								}
							} else {
								try {
									rafrw.writeStringRAF(raf, offset, " ");
								} catch (IOException e) {
									e.printStackTrace();
								}
							}

						} else if ("String".equals(type)) {
							if (contains) {
								try {
									rafrw.writeStringRAF(raf, offset, In);
								} catch (IOException e) {
									e.printStackTrace();
								}
							} else {
								try {
									rafrw.writeStringRAF(raf, offset, " ");
								} catch (IOException e) {
									e.printStackTrace();
								}
							}
						} else if ("Double".equals(type)) {
							if (contains) {
								Double dbIn = Double.valueOf(In);
								try {
									rafrw.writeDoubleRAF(raf, offset, dbIn);
								} catch (IOException e) {
									e.printStackTrace();
								}
							} else {
								try {
									rafrw.writeDoubleRAF(raf, offset, 0.0);
								} catch (IOException e) {
									e.printStackTrace();
								}
							}

						} else if ("Boolean".equals(type)) {
							if (contains) {
								Boolean blIn = Boolean.valueOf(In);
								try {
									rafrw.writeBooleanRAF(raf, offset, blIn);
								} catch (IOException e) {
									e.printStackTrace();
								}
							} else {
								// 若是flag，默认为true；其他默认为false
								try {
									if ("flag".equals(allInfo[i][0])) {
//										System.out.println("flag置为true！");
										rafrw.writeBooleanRAF(raf, offset, true);
									} else {
										rafrw.writeBooleanRAF(raf, offset, false);
									}
								} catch (IOException e) {
									e.printStackTrace();
								}
							}

						} else {
////		                    输出表模式信息看一下
//							for (String[] s : allInfo) {
//								for (String st : s) {
//									System.out.print(st + " ");
//								}
//								System.out.println();
//							}
							u1.setLogs("Errors: Unknown error occurred ~Logs: " + u1.toString() + "  \n>>INSERT IOTO table "
									+ tableName + " failure");
							return u1;
						}
					}
					try {
//						System.out.println(raf.length()+"----");
						raf.close();
					} catch (IOException e) {
						e.printStackTrace();
					}

				} else {
					u1.setLogs("Errors: Unknown error occurred ~Logs: " + u1.toString() + "  \n>>INSERT IOTO table "
							+ tableName + " failure");
					return u1;
				}
				u1.setLogs("OK~Logs: "+ u1.toString()
				+ "  \n>>INSERT IOTO table " + tableName + " success");
				return u1;
			}
			// 查看库是否有这个文件
			// 若有，插入；若无，error
		}

		u1.setLogs("Errors: 1146 - Table '" + tableName + "' doesn't exist" + "~Logs: " + u1.toString()
				+ "  \n>>INSERT IOTO table " + tableName + " failure");
		return u1;

	}

	// 测试插入语句
//	public static void main(String[] args) {
//		User u1 = new User();
//		u1.setUseDB("hhh");
////		u1 = new InsertStatement().processInsert("Insert INTO t_student (sno,sname,age,class,phone,grade)"
////				+ " values ('20200001','张同学',18,'2020','13181111111',85.9);", u1);
//		u1 = new InsertStatement().processInsert("Insert INTO t_stu (sname,age,class,grade)"
//				+ " values ('张同学',18,'2020',80);", u1);
//		System.out.println(u1.getLogs());
//	}
}
