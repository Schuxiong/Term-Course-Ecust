 
class ClassLoaderTestParent{
  static {
      System.out.println("  执行父类中的static块　　 ");
  }
  public static int age1=getAge1();
  public String str1=getString1();

  public ClassLoaderTestParent(){
	  System.out.println("  执行父类的构造方法　ClassLoaderTestParent()");
	  System.out.println();
  }

  public static int  getAge1(){
	  System.out.println("  给父类中的类变量age1赋值:　getAge1()");
	  return 1;
  }

  public static String getString1(){
	  System.out.println("  给父类中的实例变量str1赋值:　getString1()");
	  return "String ";
  }

  { 
	  System.out.println("  执行父类中的 实例块　　　 ");
	  
  }   
}


public class ClassLoaderTest extends ClassLoaderTestParent{
 static {
       System.out.println("  执行子类中的static块　 ");
  }
  public static int age2=getAge2();
  public String str2=getString2();

  public ClassLoaderTest(){
	  super();
	  System.out.println("  执行子类的构造方法　ClassLoaderTest()");
  }

  public static int  getAge2(){
	  System.out.println("  给子类中的类变量age2赋值:getAge2()");
	  return 2;
  }

  public static String getString2(){
	  System.out.println("  给子类中的实例变量str2赋值:getString2()");
	  return "String2 ";
  }

  { 
	  System.out.println("  执行子类中的 实例块 ");
	  
  }
  

  public static void main(String[] args){

    

	ClassLoaderTest c1;
    System.out.println("----------------before new----------------- ");
	c1=new ClassLoaderTest();
	System.out.println("----------------after new------------------ ");
  }
}

/*结果  

  执行父类中的static块　　 
  给父类中的类变量age1赋值:　getAge1()
  执行子类中的static块　 
  给子类中的类变量age2赋值:getAge2()
----------------before new----------------- 
  给父类中的实例变量str1赋值:　getString1()
  执行父类中的 实例块　　　 
  执行父类的构造方法　ClassLoaderTestParent()

  给子类中的实例变量str2赋值:getString2()
  执行子类中的 实例块 
  执行子类的构造方法　ClassLoaderTest()
----------------after new------------------ 

*/