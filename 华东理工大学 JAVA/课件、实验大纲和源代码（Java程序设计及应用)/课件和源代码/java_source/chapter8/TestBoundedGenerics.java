  class Box<T extends Integer> { 
     // T stands for "Type" 
     private T t; 
     public void add(T t) {  this.t = t;     } 
     public T get() {     return t;      }  
}

public class TestBoundedGenerics{
	public static void main(String[] args) {
      Integer intObject=new Integer(1);
	  String  strObject=new String("tom");
	 // Box<String> mybox=new Box<String>();
	  Box<Integer> mybox=new Box<Integer>();
	  mybox.add(intObject);
	  
	   

	}
}
