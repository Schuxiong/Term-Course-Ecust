class Employee{
	private int age;
	public void setAge(int age){this.age=age;}
	public int getAge(){return age;}
}

public class Box{
	private Object object;
	public Box( ){ 		super();	}
	public Box(Object object){		super();		this.object=object;	}

	public void add(Object object){this.object=object;}
	public Object get(){return object;} 

	public static void main(String[] args) {
		 
        String strObject=null;
		Employee tom=new Employee( );
		tom.setAge(20);
		Box myBox=new Box();
		myBox.add(tom);//upcasting
        //strObject=(String)myBox.get( ); //������ȷ�����б���    //��û��һ�ּ��������ڱ����ڼ䣬�Ϳ����ҳ����� ������
		//Employee jack=  myBox.get( ); //���뱨��     Object->String ��Ҫdowncasting
		Employee jack= (Employee)myBox.get( );//������ȷ��������ȷ
		System.out.println(jack.getAge());
	}
}
