package utils;

import java.io.IOException;
import java.io.RandomAccessFile;
/**
 * 通过RandomAccessFile 读、写 整形、字符串、double、boolean
 */
public class RandomAccessFileRW {

	/**
	 * 文件指定位置读出整形数据
	 * @return 指定位置的整形
	 */
	public int readIntRAF(RandomAccessFile file, int pos) throws IOException {
		// seek() 设置到此文件开头测量到的文件指针偏移量，在该位置发生下一个读取或写入操作
		file.seek(pos);
		return file.readInt();
	}

	/**
	 * 文件指定位置读出字符串数据
	 * @return 指定位置的字符串
	 */
	public String readStringRAF(RandomAccessFile file, int pos) throws IOException {
		file.seek(pos);// 根据偏移量移到要读取的位置
		int len = file.readInt();  //返回的是字符串长度（写入时已写入）
		byte[] bytes = new byte[len];// 通过数组读出字符串 
		file.read(bytes);
		return new String(bytes);// 返回字符串
	}

	/**
	 * 文件指定位置写入整形数据
	 * @return 整形长度：4字节
	 */
	public int writeIntRAF(RandomAccessFile file, int pos, int num) throws IOException {
		file.seek(pos);
		file.writeInt(num);
		return Integer.BYTES;// 返回的是写入长度，辅助计算偏移量
	}

	/**
	 * 文件指定位置写出字符串数据
	 * @return 写入字符长度：4+字符串字节长度
	 */
	public int writeStringRAF(RandomAccessFile file, int pos, String str) throws IOException {
		int n = 0;
		   int len = 0;
		   for(int i = 0; i < str.length(); i++) {
			   n = (int)str.charAt(i);
			   if(19968 <= n && n <40869) {
				   len += 3;//汉字字符长度为3
			   }else {
				   len += 1;
			   }
		   }
		// 英文和数字占一个字节,中文占两个字节（即一个字符） 一个 int 占 4 个字节 --大雾
		file.seek(pos);
		byte[] bytes = str.getBytes();// 将字符串存为字符数组
		file.writeInt(len); //先写入字符串长度，
		file.write(bytes);  //后写入字符串 （通过数组写入）
		return Integer.BYTES + len;   // 返回的是写入的整数和字符串长度，辅助计算偏移量
	}

	/**
	 * 文件指定位置读取布尔值
	 * @throws IOException
	 */
	public  Boolean readBooleanRAF(RandomAccessFile f, int pos) throws IOException {
	      f.seek(pos);
	      return f.readBoolean();
	   }
 
	/**
	 * 指定位置写入布尔值
	 * @throws IOException
	 */
	public  int writeBooleanRAF(RandomAccessFile f, int pos, Boolean b) throws IOException {
	      f.seek(pos);
	      f.writeBoolean(b);
	      return Integer.BYTES;
	   }
	
	/**
	 * 指定位置读取double
	 * @throws IOException
	 */
	public double readDoubleRAF(RandomAccessFile f, int pos) throws IOException {
	      f.seek(pos);
	      return f.readDouble();
	   }

	/**
	 * 指定位置写入double
	 * @throws IOException
	 */
	public int writeDoubleRAF(RandomAccessFile f, int pos, double d) throws IOException {
	      f.seek(pos);
	      f.writeDouble(d);
	      return Double.BYTES;
	   }
	
	/**
	 * 思考：如何实现其他数据类型的操作：如 日期、如何实现大对象的存储和操作，如 二进制照片、视频 未实现！
	 */
	public int writeImageRAF(RandomAccessFile file, int pos, byte[] img) {
		return 0;
	}

}
