package c;
import a.*;
import b.*;
public class C 
{
	 public static void main(String[] args){

	   System.out.println("---------------Ĭ�� A ��-----------------");
       /*
	   A a=new A();  //���ܷ��ʲ�ͬ���е�Ĭ�����ε���
	    
	   a.x1=1;
	   a.x2=2;
	   a.x3=3;
	   a.x4=4;
	   
	   System.out.println(a.x1);
	   System.out.println(a.x2);
	   System.out.println(a.x3);
	   System.out.println(a.x4);
       */

	   System.out.println("---------------public B  ��-----------------");
       B b=new B();  //ֻ�ܷ��ʲ�ͬ����public���ε���
	   b.y1=1;       //���ܷ��ʵ����ǰ���£�������ֻ�ܷ��ʸ�����public���εĳ�Ա
	   /*
	   b.y2=2;
	   b.y3=3;
	   b.y4=4;
	   */       
	   
	   System.out.println(b.y1);
	   /*
	   System.out.println(b.y2);
	   System.out.println(b.y3);
	   System.out.println(b.y4);
	   */


	 }
}
