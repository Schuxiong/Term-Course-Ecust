 
class ClassLoaderTest{
 static {
       System.out.println(" ִ�о�̬ �� static ��block ");
  }
  public static int age=getAge();
  public String str=getString();

  public ClassLoaderTest(){
	  System.out.println(" ִ�� ���췽����ClassLoaderTest()");
  }

  public static int  getAge(){
	  System.out.println("ִ�� getAge() ���������age��ֵ");
	  return 1;
  }

  public static String getString(){
	  System.out.println(" ִ�� getString(),��ʵ������str��ֵ");
	  return "String ";
  } 
  { 
	  System.out.println(" ִ��ʵ�� �顡block "); 
  } 
}



public class ClassLoaderTest2
{
	public static void main(String[] args){
	ClassLoaderTest c1; //����䲻���ʼ����ClassLoaderTest��ִ����飬�෽��
    System.out.println("before new ");
	c1=new ClassLoaderTest(); //������ʼ����ClassLoaderTest��ִ����飬�෽��, Ȼ�������ɶ��󣨳�ʼ��ʵ��������ִ�й��췽��)
	System.out.println("after new ");

	 
  }
};

/*���

  before new 
 ִ�о�̬ �� static ��block 
ִ�� getAge() ���������age��ֵ
 ִ�� getString(),��ʵ������str��ֵ
 ִ��ʵ�� �顡block 
 ִ�� ���췽����ClassLoaderTest()
after new 

*/
