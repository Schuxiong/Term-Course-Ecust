class Box<T> {      
   private T t; 
   public void add(T t) {  this.t = t;     } 
   public T get() {     return t;      }

   public <U> void printClassName(U u){ 
      System.out.println("T: " + t.getClass().getName()); 
      System.out.println("U: " + u.getClass().getName()); 
    }   
}
public class TestGenericMethod{
	public static void main(String[] args) {
      Integer intObject=new Integer(1);
	  String  strObject=new String("tom");
	  Box<String> mybox=new Box<String>();
	  mybox.add(strObject);
	  mybox.<Integer>printClassName(intObject);
	 // mybox.printClassName(intObject);//type inference,��ʡ��<U>


	}
}