 
class ClassLoaderTest{
 static {
       System.out.println(" 执行静态 块 static 　block ");
  }
  public static int age=getAge();
  public String str=getString();

  public ClassLoaderTest(){
	  System.out.println(" 执行 构造方法　ClassLoaderTest()");
  }

  public static int  getAge(){
	  System.out.println("执行 getAge() ，给类变量age赋值");
	  return 1;
  }

  public static String getString(){
	  System.out.println(" 执行 getString(),给实例变量str赋值");
	  return "String ";
  } 
  { 
	  System.out.println(" 执行实例 块　block "); 
  } 
}



public class ClassLoaderTest2
{
	public static void main(String[] args){
	ClassLoaderTest c1; //该语句不会初始化类ClassLoaderTest：执行类块，类方法
    System.out.println("before new ");
	c1=new ClassLoaderTest(); //该语句初始化类ClassLoaderTest：执行类块，类方法, 然后再生成对象（初始化实例变量，执行构造方法)
	System.out.println("after new ");

	 
  }
};

/*结果

  before new 
 执行静态 块 static 　block 
执行 getAge() ，给类变量age赋值
 执行 getString(),给实例变量str赋值
 执行实例 块　block 
 执行 构造方法　ClassLoaderTest()
after new 

*/
