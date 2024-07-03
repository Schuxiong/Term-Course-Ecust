package create;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

import utils.Block;
import utils.Page;

/**
 * 管理当前打开的数据库下的表或日志等(目前只管理一个，，，记得及时关闭!!!)
 * 该类用于文件读写、追加块及文件     需要占用的块数、号等    ps:追加块真香！
 * 可用于缓冲区管理
 */
public class FileMgr {
	
	private java.io.File fileFile; //指定数据文件 或 日志文件 
	private int blkSize;//文件分布在磁盘块的容量
	private RandomAccessFile f ; //一个未关闭的f
	
	public RandomAccessFile getF() {
		return f;
	}

	public FileMgr(String fileName, int blkSize) {
		this.fileFile = new java.io.File(fileName);
		this.blkSize = blkSize;
		if(!fileFile.exists()) {
			try {
				fileFile.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		try {
			this.f = new RandomAccessFile(fileFile,"rws");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	//把要读取的内容先通过逻辑块blk装入内存页p,再进行读取
	public synchronized void read(Block blk,Page p) {
		try {
			f.seek(blk.getBlockID() * blkSize);
			f.getChannel().read(p.contents());
		}catch (IOException e) {
			throw new RuntimeException("不能读取块block(blk)"+blk);
		}
	}
	
	//把要写入的内容先通过逻辑块blk装入内存页p,再进行写入
	public synchronized void write(Block blk,Page p) {
		try {
			f.seek(blk.getBlockID() * blkSize);
			f.getChannel().write(p.contents());
		}catch (IOException e) {
			throw new RuntimeException("不能写入块block(blk)"+blk);
		}
	}
	
	//返回追加逻辑块对象（被字节数组初始化过的），失败则报异常
	public synchronized Block append(String fileName) {
		int newBlockID = fileBlockID(fileName);
		Block blk = new Block(fileName, newBlockID);
		byte[] b = new byte[blkSize];
		try {
			f.seek(blk.getBlockID()*blkSize);
			f.write(b);
		}catch (IOException e) {
			throw new RuntimeException("不能追加blk " + blk);
		}
		return blk;
	}

	//得到文件的逻辑块blk号=块数,因为无论建立日志还是数据文件，
  	//每个文件最小都是blksize的1倍，所以返回值一定是正整数
	private int fileBlockID(String fileName) {
		try {
	         return (int)(f.length() / blkSize);
	      }catch (IOException e) {
	         throw new RuntimeException("不能访问 " + fileName);
	      }
	}
	
	//返回逻辑块的大小 blkSize
	   public int blkSize() {
	      return blkSize;
	   }
}
