public class TestEmployee 
{
	static {
       
        System.out.println("TestEmployee���еľ�̬�� " );//�����ೣ���������ʼ���� :id,country
		
	}
	public static void main(String[] args) throws Exception
	{
		/*
		Employee  tom=null; //���������		
		System.out.println("-------111111111111--------------");		 
		Class c1=null; //��Class�Ķ���c1
		System.out.println("-------222222222222--------------");
	    c1=ClassLoader.getSystemClassLoader().loadClass("Employee" );//������Employee,��û�г�ʼ��static����		
		System.out.println("-------333333333333--------------");
		//tom=(Employee)c1.newInstance();//ʵ�����࣬����һ��Employee����:tom, ���ʼ��static����:id,country
		System.out.println(" "+Employee.id);//�����������Ҳ���ʼ��static����:id,country
		System.out.println("-------444444444444--------------");
	    */
     
	    Employee  tom=null; //���������		
		Class c1=null; //��Class�Ķ���c1
		c1=ClassLoader.getSystemClassLoader().loadClass("Employee" );//������Employee,��û�г�ʼ��static����		
		 tom=(Employee)c1.newInstance();//ʵ�����࣬����һ��Employee����:tom, ���ʼ����:id,country
		//System.out.println(" "+Employee.id);//�����������Ҳ���ʼ���� :id,country
		// System.out.println(" "+Employee.k);//�����ೣ���������ʼ���� :id,country
		 


		 
	}
}
