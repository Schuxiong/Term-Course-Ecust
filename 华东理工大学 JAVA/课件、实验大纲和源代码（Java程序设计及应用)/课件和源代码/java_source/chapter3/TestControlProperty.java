public class  TestControlProperty
{
    public void test(){

      //---��ͬһ�����У����Է���public ,default��-------------------------------------
		PublicClass publicClass=new PublicClass();
        DefaultClass defaultClass=new DefaultClass();
		//---------------------------------------- 
        

		//------��ͬһ�����У����ܷ�����������£� 
		//---   ����private��Ա���ܷ����⣬������Ա���ܱ�����
        /*
		public int age;
        protected String name;
        float x;
        private boolean y;
		*/

		publicClass.age=1;
		publicClass.name="11";
		publicClass.x=1.0f;
		publicClass.y=true; //error

 
        defaultClass.age=1;
		defaultClass.name="11";
		defaultClass.x=1.0f;
		defaultClass.y=true;//error

	}

	public static void main(String[] args) 
	{
		 
		 
        TestControlProperty testControlProperty=new TestControlProperty();
        testControlProperty.test();

	}
}
