package utils;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 * 与SchemaFile交互，读取SchemaFile文件，可进一步获取对应表的表结构信息 打开、读取、关闭
 * 
 * @author 卅TAT
 *
 */
public class SchemaInfo {

	private int tableID = -1; // table 在schema中序号从1开始
	private int fieldNum; // table 中 域的数量
	private String shaAbsPath;
	private String tableName;
	private Boolean hasTable; // schem有该表，此时可获取表结构信息 getIofo
	private String[] fieldName;

	public String[] getFieldName() {
		return fieldName;
	}

	public void setFieldName(String[] fieldName) {
		this.fieldName = fieldName;
	}

	public String getTableName() {
		return tableName;
	}

	private int pointStart;
	private int blockSize = 256;

	/**
	 * 初始化，若存在hasTable=true，指针已更新，可直接获取表结构信息
	 * 
	 * @param shaAbsPath 表结构文件的绝对路径
	 * @param tableName  待查表的表名
	 */
	public SchemaInfo(String shaAbsPath, String tableName) {
		this.shaAbsPath = shaAbsPath;
		this.tableName = tableName;
		RandomAccessFile sha = null;
		RandomAccessFileRW sharw = new RandomAccessFileRW();
		int point = 0;
		long fileLength = 0;
		String tblName = null;
		try {
			sha = new RandomAccessFile(shaAbsPath, "rws");
			fileLength = sha.length();
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		} catch (IOException e2) {
			e2.printStackTrace();
		}

		int count = 0;
		while (point <= fileLength) {
//			System.out.println("fileLength:" + fileLength);
			count++;
			try {
				tblName = sharw.readStringRAF(sha, point);
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (tableName.equals(tblName)) {// 找到啦！
				this.hasTable = true;
				try {
					this.fieldNum = sharw.readIntRAF(sha, point + 15);
				} catch (IOException e) {
					e.printStackTrace();
				}
				this.tableID = count;
				this.pointStart = point;
				break;
			}
			point += blockSize;
		}
		try {
			sha.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	// 查到表名
	// 设置tableID,返回域数量，计算每个域的开始pos、域名、域类型、域长度、偏移量
	public String[][] getInfo() {
		this.fieldName = new String[this.fieldNum];
		String[][] all = new String[this.fieldNum][4];
		RandomAccessFile sha = null;
		RandomAccessFileRW sharw = new RandomAccessFileRW();
		try {
			sha = new RandomAccessFile(this.shaAbsPath, "rws");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}

		// fieldNum -- 7 开始坐标pointStart 域名、域类型、域长度、偏移量
		int i = 0;
		while (i < this.fieldNum) {
			try {
				all[i][0] = sharw.readStringRAF(sha, pointStart + 30 * (i+1));// 域名
				all[i][1] = Integer.toString(sharw.readIntRAF(sha, pointStart + 30 * (i+1) + 15));// 域类型
				all[i][2] = Integer.toString(sharw.readIntRAF(sha, pointStart + 30 * (i+1) + 20));// 域长度，存放表格内容最大长度
				all[i][3] = Integer.toString(sharw.readIntRAF(sha, pointStart + 30 * (i+1) + 25));// 偏移量，表内容开始写入位置
			} catch (IOException e) {
				e.printStackTrace();
			}
			i++;
		}
		for(int j = 0; j < all.length; j++) {
			this.fieldName[j] = all[j][0];
		}
		try {
			sha.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return all;
	}

	public int getFieldNum() {
		return this.fieldNum;
	}

	public boolean hasTable() {
		return hasTable;
	}

	public int getTableID() {
		return tableID;
	}
}
