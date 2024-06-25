package bean;

import java.util.ArrayList;

import utils.Table;

/**
 * 处理where子句，将符合条件的结果下标ArrayList<Integer>返回 此处对查询失败不返回具体信息！
 */
public class WhereType {

	public ArrayList<Integer> getType(String statement, Table fv) {
		String state = statement.toLowerCase().replace(";", "");
		String[] where = state.split("where");

		ArrayList<Integer> queryIndex = new ArrayList<Integer>();
		if (where.length > 1) {
			// 获取行号，从0开始
			where[1] = where[1].trim();
//			System.out.println(where[1]);//条件表达式，处理！获取可返回的行！
			if (where[1].contains("=") && (!where[1].contains("!="))) {
				String fdn = where[1].split("=")[0].trim(); // 条件字段名
				String con = where[1].split("=")[1].trim(); // 条件值
				// 字符串
				if (con.contains("'") || con.contains("\"")) {
					con = con.replace("'", "").replace("\"", "");
					ArrayList<String> allColumnValue = fv.getTblFVString().get(fdn);
					if (allColumnValue != null) {
						for (int i = 0; i < allColumnValue.size(); i++) {
							if (con.equals(allColumnValue.get(i))) {
								queryIndex.add(i);
							}
						}
//						System.out.println("字符串等值比较结果：" + queryIndex.toString());
					}
				} else {// 数值比较
					ArrayList<Integer> allColumnValue = fv.getTblFVInt().get(fdn);
					if (allColumnValue != null) {
						for (int i = 0; i < allColumnValue.size(); i++) {
							if (Integer.valueOf(con) == allColumnValue.get(i)) {
								queryIndex.add(i);
							}
						}
//						System.out.println("数值等值比较结果：" + queryIndex.toString());
					}else {
						ArrayList<Double> allColumnValue1 = fv.getTblFVDouble().get(fdn);
						System.out.println("查询列数据："+allColumnValue1);
						if (allColumnValue1 != null) {
							for (int i = 0; i < allColumnValue1.size(); i++) {
								//double数值比较：特殊！
								if((allColumnValue1.get(i)-Double.valueOf(con)> -0.000001)
										&& (allColumnValue1.get(i)-Double.valueOf(con) < 0.000001)) {
									queryIndex.add(i);
								}
							}
						}
					}
				}
				// 其他的都是数值比较！ 数值比较分整形和double
			} else {
				if (where[1].contains(">") && (!where[1].contains("<"))) {
					String fdn = where[1].split(">")[0].trim();
					String con = where[1].split(">")[1].trim();
					ArrayList<Integer> allColumnValue = fv.getTblFVInt().get(fdn);
					if (allColumnValue != null) {
						for (int i = 0; i < allColumnValue.size(); i++) {
							if (allColumnValue.get(i) > Integer.valueOf(con)) {
								queryIndex.add(i);
							}
						}
//						System.out.println("数值等值比较结果：" + queryIndex.toString());
					} else {
						ArrayList<Double> allColumnValue1 = fv.getTblFVDouble().get(fdn);
						if (allColumnValue1 != null) {
							for (int i = 0; i < allColumnValue1.size(); i++) {
								if (allColumnValue1.get(i) > Double.valueOf(con)) {
									queryIndex.add(i);
								}
							}
						}
					}
				} else if (where[1].contains("<") && (!where[1].contains(">"))) {
					String fdn = where[1].split("<")[0].trim();
					String con = where[1].split("<")[1].trim();
					ArrayList<Integer> allColumnValue = fv.getTblFVInt().get(fdn);
					if (allColumnValue != null) {
						for (int i = 0; i < allColumnValue.size(); i++) {
							if (allColumnValue.get(i) < Integer.valueOf(con)) {
								queryIndex.add(i);
							}
						}
//						System.out.println("数值等值比较结果：" + queryIndex.toString());
					} else {
						ArrayList<Double> allColumnValue1 = fv.getTblFVDouble().get(fdn);
						if (allColumnValue1 != null) {
							for (int i = 0; i < allColumnValue1.size(); i++) {
								if (allColumnValue1.get(i) < Double.valueOf(con)) {
									queryIndex.add(i);
								}
							}
						}
					}
				} else if (where[1].contains("<>") || where[1].contains("!=")) {
//					System.out.println("不等于比较");
					String fdn = null; // where 中的 字段名
					String con = null; // where 中的 条件值
					if (where[1].contains("<>")) {
						fdn = where[1].split("<>")[0].trim();
						con = where[1].split("<>")[1].trim();
					} else {
						fdn = where[1].split("!=")[0].trim();
						con = where[1].split("!=")[1].trim();
					}
					ArrayList<Integer> allColumnValue = fv.getTblFVInt().get(fdn);
					if (allColumnValue != null) {
//						System.out.println("整数比较");
						for (int i = 0; i < allColumnValue.size(); i++) {
							if (allColumnValue.get(i) != Integer.valueOf(con)) {
								queryIndex.add(i);
							}
						}
//						System.out.println("数值等值比较结果：" + queryIndex.toString());
					} else {
//						System.out.println("浮点数比较");
						ArrayList<Double> allColumnValue1 = fv.getTblFVDouble().get(fdn);
						System.out.println(allColumnValue1.toString());
						if (allColumnValue1 != null) {
							for (int i = 0; i < allColumnValue1.size(); i++) {
								if (!((allColumnValue1.get(i)-Double.valueOf(con)> -0.000001)
										&&( allColumnValue1.get(i)-Double.valueOf(con) < 0.000001))) {
									System.out.println(allColumnValue1.get(i));
									queryIndex.add(i);
								}
							}
						}
					}
				}
			}
		} else {// 无where子句
//			System.out.println(where[0]); 
//			System.out.println("全部查询！");
			ArrayList<Boolean> allColumnValue = fv.getTblFVBoolean().get("flag");
			if (allColumnValue != null) {
				for (int i = 0; i < allColumnValue.size(); i++) {
					queryIndex.add(i);
				}
			}
		}
		return queryIndex;
	}
}
