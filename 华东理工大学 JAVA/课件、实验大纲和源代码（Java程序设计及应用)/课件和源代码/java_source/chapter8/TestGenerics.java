/** 
 * Generic version of the Box class. 
 * @param <T> the type of the value being boxed 
*/ 
class Box<T> { 
     // T stands for "Type" 
     private T t; 
     public void add(T t) {  this.t = t;     } 
     public T get() {     return t;      }  
} 

class Employee{
	private int age;
	public void setAge(int age){this.age=age;}
	public int getAge(){return age;}
}

public class TestGenerics{
	public static void main(String[] args) {
        String strObject=null;
		Employee tom=new Employee( );
		tom.setAge(20);
		Box<Employee> myBox=new Box<Employee>();
		 System.out.println(myBox.toString());
		myBox.add(tom);//upcasting
        //strObject= myBox.get( );//编译报错正确  
		//Employee jack= (Employee)myBox.get( );//编译正确，运行正确
		 Employee jack=  myBox.get( );//不需要Cast
		System.out.println(jack.getAge());
 
      /*
         Box2<Employee> myBox2=new Box2<Employee>();
		 myBox2.add(tom); 
		  Employee rose=  myBox2.get( );//不需要Cast
		  System.out.println(rose.getAge());

		 // BoxInterface<Employee> myBox3=new Box2<Employee>();
		  BoxInterface  myBox3=new Box2<Employee>();
		 myBox3.add(tom); 
		  Employee sun=(Employee)  myBox3.get( );//不需要Cast
		  System.out.println(sun.getAge());
		  */
 
         
		 

	}

}
