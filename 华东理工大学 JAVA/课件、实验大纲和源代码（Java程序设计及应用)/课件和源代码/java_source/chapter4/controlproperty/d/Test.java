package d;
import a.*;
import b.*;

//���ܼ̳б�İ�����Ĭ���������ε���
/*
class  D extends A
{
	  
	public void prn(){
      System.out.println("x1:"+x1+"  x2: "+x2+"  x3:"+x3+"  x4:"+x4);
	}
}
*/

//�ܼ̳б�İ�����public�������ε���
class  E extends B
{
	public void prn(){
	  //���ܷ���Ĭ�ϡ�˽���������εĳ�Ա,ֻ�ܷ���public ,protected���εĳ�Ա
	  y1=1;  //public
	  y2=2;  //protected
	  // y3=3; //Ĭ��
	  // y4=4; //˽��
	   
      System.out.println("y1:"+y1+"  y2: "+y2 );
     // System.out.println( "  y3:"+y3+"  y4:"+y4);
	}  
}

public class Test
{   public static void main(String[] args){
      //D d=new D();
	 // d.prn();
	  E e=new E();
	  e.prn();

    }
}
