package utils;

import java.util.ArrayList;
import java.util.Map;

public class Table {
	Map<String, ArrayList<String>> tblFVString; // 5个类型，段名:[值1,值2,值3...]
	Map<String, ArrayList<Integer>> tblFVInt;
	Map<String, ArrayList<Double>> tblFVDouble;
	Map<String, ArrayList<Character>> tblFVChar;
	Map<String, ArrayList<Boolean>> tblFVBoolean;
	public Map<String, ArrayList<String>> getTblFVString() {
		return tblFVString;
	}
	public void setTblFVString(Map<String, ArrayList<String>> tblFVString) {
		this.tblFVString = tblFVString;
	}
	public Map<String, ArrayList<Integer>> getTblFVInt() {
		return tblFVInt;
	}
	public void setTblFVInt(Map<String, ArrayList<Integer>> tblFVInt) {
		this.tblFVInt = tblFVInt;
	}
	public Map<String, ArrayList<Double>> getTblFVDouble() {
		return tblFVDouble;
	}
	public void setTblFVDouble(Map<String, ArrayList<Double>> tblDouble) {
		this.tblFVDouble = tblDouble;
	}
	public Map<String, ArrayList<Character>> getTblFVChar() {
		return tblFVChar;
	}
	public void setTblFVChar(Map<String, ArrayList<Character>> tblFVChar) {
		this.tblFVChar = tblFVChar;
	}
	public Map<String, ArrayList<Boolean>> getTblFVBoolean() {
		return tblFVBoolean;
	}
	public void setTblFVBoolean(Map<String, ArrayList<Boolean>> tblFVBoolean) {
		this.tblFVBoolean = tblFVBoolean;
	}
}
