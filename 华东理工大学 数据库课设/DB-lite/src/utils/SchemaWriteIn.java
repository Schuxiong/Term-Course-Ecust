package utils;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import bean.DataType;
/**
 * 写入模式表！写完后关闭raf
 * @author 卅TAT
 *
 */
public class SchemaWriteIn {

	private int BlockSize = 256;
	private int fieldNum ;
	
	public SchemaWriteIn(String schema, String tbName, String[][] nameAttrLen) {
		this.fieldNum = nameAttrLen.length+1;
		// 如果表结构不存在，创建文件、块并写入内容
		File schemaFile = new java.io.File(schema);
		if(!schemaFile.exists()) {
			try {
				schemaFile.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		//如果表名已经存在，不添加！（此处先不考虑修改表结构）
//		int count = 0;
//		while (point <= fileLength) {
////			System.out.println("fileLength:" + fileLength);
//			count++;
//			try {
//				tblName = sharw.readStringRAF(sha, point);
//			} catch (IOException e) {
//				e.printStackTrace();
//			}
//			if (tableName.equals(tblName)) {// 找到啦！
//				this.hasTable = true;
//				try {
//					this.fieldNum = sharw.readIntRAF(sha, point + 15);
//				} catch (IOException e) {
//					e.printStackTrace();
//				}
//				this.tableID = count;
//				this.pointStart = point;
//				break;
//			}
//			point += blockSize;
//		}
//		
//		
//		
		RandomAccessFile raf = null;
		try {
			raf = new RandomAccessFile(schemaFile, "rws");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		int pos = 0;   //  0-0 1-256  256
		RandomAccessFileRW rafRW = new RandomAccessFileRW();
		try {
			if(raf.length()==0) {
				pos = 0;
			}else{
				pos = ((int)(raf.length()/BlockSize)+1)*256;   //从0，256，512开始写
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
//		String tablePath = schema.split("\\.")[0];
//		String separator = File.separator;
//		String[] tableName = tablePath.split("\\" + separator);  //获取表名，此处只是schema
//		int len = tableName.length;
		try {
			rafRW.writeStringRAF(raf, pos, tbName);
			int fieldNum = nameAttrLen.length+1;  //加上flag列
			
			rafRW.writeIntRAF(raf, pos+15, fieldNum); //写入域数量
//			System.out.println(rafRW.readIntRAF(raf, pos+15)+"写入！应该为"+fieldNum);
			int offset = 0;
			for(int i = 0; i < fieldNum; i++) {
				if(i == 0) {
					rafRW.writeStringRAF(raf, pos+30*(i+1), "flag");//写入字段名
					rafRW.writeIntRAF(raf, pos+30*(i+1)+15, 5); //写入类型（数字）
					rafRW.writeIntRAF(raf, pos+30*(i+1)+20, 4);//写入长度
					rafRW.writeIntRAF(raf, pos+30*(i+1)+25, 0);//写入偏移量
					offset+= 4;
				}else {
					rafRW.writeStringRAF(raf, pos+30*(i+1), nameAttrLen[i-1][0]);//写入字段名
					int type = new DataType().setDataType(nameAttrLen[i-1][1]);
					rafRW.writeIntRAF(raf, pos+30*(i+1)+15, type); //写入类型（数字）
					rafRW.writeIntRAF(raf, pos+30*(i+1)+20, Integer.valueOf(nameAttrLen[i-1][2]));//写入长度
					rafRW.writeIntRAF(raf, pos+30*(i+1)+25, offset);//写入偏移量
					if("string".equals(nameAttrLen[i-1][1])) {
						offset +=(Integer.valueOf(nameAttrLen[i-1][2]))+4;//字符串前有个记录长度的整形
					}else if(("char".equals(nameAttrLen[i-1][1]))){
						offset +=(Integer.valueOf(nameAttrLen[i-1][2]))+4;//字符前有个记录长度的整形,char其实就是string
					}else {
						offset +=Integer.valueOf(nameAttrLen[i-1][2]);
					}
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		try {
			raf.close(); //关闭模式表
		} catch (IOException e) {
			e.printStackTrace();
		}
		/*
		 * sno String 8 
		 * name String 15 
		 * age int 4 
		 * class String 4 
		 * phone String 11 
		 * grade double 8
		 */		
//		p.setString(0, tablename);
	}//end UseSchema

	//插入一列，目前每个表最多七个域！（包括
	public Boolean canAddField() {
		if(this.fieldNum<7) {
			return true;
		}
		return false;
	}
	
}
