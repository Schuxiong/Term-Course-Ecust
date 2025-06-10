package create;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import bean.DataType;
import utils.RandomAccessFileRW;
import utils.SchemaInfo;
import utils.Table;
import utils.User;

/**
 * 读取指定table的每列信息
 * 
 * @author 卅TAT
 *
 */
public class TableRead {
	private String FilePath = "E:\\Java\\database"; // 数据库主路径
	Map<String, ArrayList<String>> tblFVString; // 5个类型，段名:[值1,值2,值3...]
	Map<String, ArrayList<Integer>> tblFVInt;
	Map<String, ArrayList<Double>> tblFVDouble;
	Map<String, ArrayList<Character>> tblFVChar;
	Map<String, ArrayList<Boolean>> tblFVBoolean;
	long fileLength;

	public TableRead() {
		tblFVBoolean = new HashMap<>();
		tblFVChar = new HashMap<>();
		tblFVDouble = new HashMap<>();
		tblFVInt = new HashMap<>();
		tblFVString = new HashMap<>();
	}

	public Table getFV(String tableName, User u1) {
		String schemaPath = FilePath + "\\" + u1.getUseDB() + "\\schema.dbs";
		SchemaInfo info = new SchemaInfo(schemaPath, tableName);
		String tblPath = FilePath + "\\" + u1.getUseDB() +"\\"+ tableName+".dbf";

		RandomAccessFile raf = null;

		String[][] allInfo = info.getInfo();// 字段信息
		int fieldNum = info.getFieldNum(); // 字段长度
		
//		String[] allfield =info.getFieldName(); // allfield 字段名

		File f = new File(tblPath);
		try {
			raf = new RandomAccessFile(f, "rws");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

//		System.out.println(f.length()+"文件长度");
		this.fileLength =  f.length();
		RandomAccessFileRW rafrw = new RandomAccessFileRW();
		int startPos = 0; // step = 128

		for (int i = 0; i < fieldNum; i++) {
			// 每个字段一个Map
			String fieldName = allInfo[i][0];
			String type = new DataType().getDataType(allInfo[i][1]);// 数值类型
			int offset = Integer.valueOf(allInfo[i][3]); // 偏移量
//			System.out.println(offset+"偏移量");
			ArrayList<Integer> arint = new ArrayList<>(1);
			ArrayList<String> arstr = new ArrayList<>(1);
			ArrayList<Double> ardbl = new ArrayList<>(1);
			ArrayList<Boolean> arbool = new ArrayList<>(1);
			ArrayList<Character> archar = new ArrayList<>(1);
			startPos = 0;
			for (int j = 0; j < f.length() / 128 + 1; j++) {// 控制次数，即值的行数
				if ("Int".equals(type)) {
					try {
						int readIntRAF = rafrw.readIntRAF(raf, startPos + offset);
						arint.add(readIntRAF);
					} catch (IOException e) {
						e.printStackTrace();
					}
					if(j+1 >= f.length() / 128 + 1) {
						this.tblFVInt.put(fieldName, arint);
					}
				} else if ("Char".equals(type)) {
					try {
						String readStringRAF = rafrw.readStringRAF(raf, startPos + offset);
						archar.add(readStringRAF.charAt(0));
					} catch (IOException e) {
						e.printStackTrace();
					}
					if(j+1 >= f.length() / 128 + 1) {
						this.tblFVChar.put(fieldName, archar);
					}

				} else if ("String".equals(type)) {
					try {
//						System.out.println("正常执行~");
						String readStringRAF = rafrw.readStringRAF(raf, startPos + offset); 
						arstr.add(readStringRAF);
//						System.out.println(arstr.toString());
					} catch (IOException e) {
						e.printStackTrace();
					}
					if(j+1 >= f.length() / 128 + 1) {
						this.tblFVString.put(fieldName, arstr);
					}
				} else if ("Double".equals(type)) {
					try {
						double readDoubleRAF = rafrw.readDoubleRAF(raf, startPos + offset);
						ardbl.add(readDoubleRAF);
					} catch (IOException e) {
						e.printStackTrace();
					}
					if(j+1 >= f.length() / 128 + 1) {
						this.tblFVDouble.put(fieldName, ardbl);
					}
				} else if ("Boolean".equals(type)) {
					try {
						Boolean readBooleanRAF = rafrw.readBooleanRAF(raf, startPos + offset);
						arbool.add(readBooleanRAF);
					} catch (IOException e) {
						e.printStackTrace();
					}
					if(j+1 >= f.length() / 128 + 1) {
						this.tblFVBoolean.put(fieldName, arbool);
					}
				} 
				startPos += 128;
			} // end for(内）
		}
		try {
			raf.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

		Table tb = new Table();
		if(tblFVBoolean!=null) {
			tb.setTblFVBoolean(tblFVBoolean);
		}
		if(tblFVString!=null) {
			tb.setTblFVString(tblFVString);
		}
		if(tblFVChar!=null) {
			tb.setTblFVChar(tblFVChar);
		}
		if(tblFVInt!=null) {
			tb.setTblFVInt(tblFVInt);
		}
		if(tblFVDouble!=null) {
			tb.setTblFVDouble(tblFVDouble);
		}
		return tb;
	}


	public long getFileLength() {
		return fileLength;
	}

}
