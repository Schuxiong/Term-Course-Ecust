package bean;

public class DataType {
	public DataType() {
	}
	public String getDataType(String  n) {
		switch(n) {
		case "1" : return "Int";
		case "2" : return "Char";
		case "3" : return "String";
		case "4" : return "Double";
		case "5" : return "Boolean";
		default: return "other";
		}
	}
	
	public int setDataType(String str) {
		switch(str) {
		case "int" : return 1;
		case "char" : return 2;
		case "string" : return 3;
		case "double" : return 4;
		case "boolean" : return 5;
		default: return 6;
		}
	}
}
