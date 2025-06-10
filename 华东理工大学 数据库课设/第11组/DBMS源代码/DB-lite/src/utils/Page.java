package utils;

import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

public class Page {
	/**
	 * java自带的字节缓冲区类 ByteBuffer，用于申请内存空间
	 */
	private ByteBuffer byteBuffer;

	/**
	 * java自带的字符集类Charset,设定文件内编码格式，默认ASCII
	 */
	public static final Charset CHARSET = StandardCharsets.UTF_8;// UTF-8

	
	/**
	 * 该构造给数据文件在内存中创建存储空间，按照块大小申请字节缓冲空间
	 */
	public Page(int blockSize) {
		byteBuffer = ByteBuffer.allocateDirect(blockSize);
	}

	
	/**
	 * 该构造给日志文件在内存里创建存储空间，按字节数组大小申请空间
	 */
	public Page(byte[] b) {
		byteBuffer = ByteBuffer.wrap(b);
	}

	/**
	 * 从内存页起始位置，返回字节缓冲区对象，File类需要
	 */
	public ByteBuffer contents() {
		byteBuffer.position(0);
		return byteBuffer;
	}
	
	/**
	 * 按照指定偏移量 offset 即位置，返回该处的整型数值
	 */
	public int getInt(int offset) {
		return byteBuffer.getInt(offset);
	}

	
	/**
	 * 按照指定偏移量 offset 即位置，设置该处的整型数值为n
	 */
	public void setInt(int offset, int n) {
		byteBuffer.putInt(offset, n);
	}
	
	
	/**
	 * 按照指定偏移量offset即位置，返回该处值的字节数组形式
	 */
	public byte[] getBytes(int offset) {
		byteBuffer.position(offset);
		int length = byteBuffer.getInt();
		byte[] b = new byte[length];
		byteBuffer.get(b);
		return b;
	}
	
	
	/**
	 * 实际写入内存：按照指定偏移量offset即位置，设置该处的值为字节数组b
	 */
	public void setBytes(int offset,byte[] b) {
		byteBuffer.position(offset);
		byteBuffer.putInt(b.length); //先写入字符数组长度
		byteBuffer.put(b);
	}
	
	
	/**
	 * 按照指定偏移量offset即位置，返回该处的字符串内容
	 */
	public String getString(int offset) {
		byte[] b = getBytes(offset);
		return new String(b,CHARSET);
	}
	
	
	/**
	 * 按照指定偏移量offset即位置，设置该处的字符串为s
	 */
	public void setString(int offset, String s) {
		byte[] b = s.getBytes(CHARSET);
		setBytes(offset,b);
	}
	
	
	/**
	 * 按照用户给定字符串长度strlen，返回需要的字节数+4
	 */
	public static int maxLength(int strlen) {
//		float bytesPerChar = CHARSET.newEncoder().maxBytesPerChar();
//		return Integer.BYTES + (strlen * (int)bytesPerChar);
		return strlen + Integer.BYTES;
	}
	
	/**
	 * 按照指定偏移量 offset 即位置，返回该处的double数值
	 */
	public double getDouble(int offset) {
		return byteBuffer.getDouble(offset);
	}

	
	/**
	 * 按照指定偏移量 offset 即位置，设置该处的double值为n
	 */
	public void setDouble(int offset, double n) {
		byteBuffer.putDouble(offset, n);
	}
	
	/**
	 * 按照指定偏移量 offset 即位置，返回该处的boolean
	 */
	public int getBoolean(int offset) {
		return byteBuffer.getInt(offset);
	}

	
	/**
	 * 按照指定偏移量 offset 即位置，设置该处的boolean值为n
	 */
	public void setBoolean(int offset, int n) {
		byteBuffer.putInt(offset, n);
	}
	
}
