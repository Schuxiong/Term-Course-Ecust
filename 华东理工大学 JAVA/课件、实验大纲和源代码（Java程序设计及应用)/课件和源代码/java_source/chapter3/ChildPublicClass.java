
 
 

public class  ChildPublicClass extends PublicClass
{

    public void test(){

      	PublicClass publicClass=new PublicClass();
      //  DefaultClass defaultClass=new DefaultClass();
		//---------------------------------------- 
        

		//------��ͬ���е�������ʸ����г�Ա�� 
		//---   ����private��Ա���ܱ������⣬������Ա���ܱ�����
        /*
		public int age;
        protected String name;
        float x;
        private boolean y;
		*/

		 publicClass.age=1;
		 publicClass.name="11";  
		 publicClass.x=1.0f;   
		 publicClass.y=true;  //���ܷ���


         //------��ͬ���е����� �� 
		 //--- �̳��˸����е�publi��protected��default��Ա,��privateû�м̳� 
		 this.age=2;
		 this.name="333";
         this.x=2.0f;    
         this.y=false;  //���ܷ���
        /*
        defaultClass.age=1;
		defaultClass.name="11";
		defaultClass.x=1.0f;
		defaultClass.y=true;
		*/

	}
	public static void main(String[] args) 
	{
		ChildPublicClass childPublicClass=new ChildPublicClass();
        childPublicClass.test();
        
		 childPublicClass.name="22";
		 childPublicClass.x=3.0f;  
         childPublicClass.y=false;  //���ܷ���
	}
}
