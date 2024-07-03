package utils;

/**
 * 该类用于表示对应磁盘块在内存中映射的逻辑块ID
 */
public class Block {
	private String filename;
	private int blockID;

	public Block() {
	}

	/**
	 * 该构造方法记录 逻辑块号blockid及块上的文件名filename， 不过也与对应的物理磁盘块一样
	 */
	public Block(String filename, int blockID) {
		this.filename = filename;
		this.blockID = blockID;
	}

	public String getFilename() {
		return filename;
	}

	public void setFilename(String filename) {
		this.filename = filename;
	}

	public int getBlockID() {
		return blockID;
	}

	public void setBlockID(int blockID) {
		this.blockID = blockID;
	}

	/**
	 * 与其它块比较 块的文件名和块号，即比较 Block 对象内容
	 */
	public boolean equals(Object obj) {
		Block blk = (Block) obj;
		return filename.equals(blk.filename) && blockID == blk.blockID;
	}

	@Override
	public String toString() {
		return "[文件名：" + filename + "，块号：" + blockID + "]";
	}
	
	/**
	 * 返回此对象内容的哈希代码
	 */
	public int hasCode() {
		return toString().hashCode();
	}

}
