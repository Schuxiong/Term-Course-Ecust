
package controlproperty.b;
import controlproperty.a.*;
//import controlproperty.a.PublicClass;
//import controlproperty.a.DefaultClass;

public class  TestControlProperty
{

    public void test(){

      //---�ڲ�ͬ���У�ֻ���Է���public  ��-------------------------------------
		PublicClass publicClass=new PublicClass();
      //  DefaultClass defaultClass=new DefaultClass();
		//---------------------------------------- 
        

		//------�ڲ�ͬ���У����ܷ�����������£� 
		//---   ����public��Ա�ܱ������⣬������Ա�����ܱ�����
        /*
		public int age;
        protected String name;
        float x;
        private boolean y;
		*/

		publicClass.age=1;
		 publicClass.name="11"; //���ܷ���
		 publicClass.x=1.0f;  //���ܷ���
		 publicClass.y=true;  //���ܷ���

        /*
        defaultClass.age=1;
		defaultClass.name="11";
		defaultClass.x=1.0f;
		defaultClass.y=true;
		*/

	}
	public static void main(String[] args) 
	{
		TestControlProperty testControlProperty=new TestControlProperty();
        testControlProperty.test();
 
	}
}
