 class AnonymousParent{
	AnonymousParent(){
	 System.out.println("Anonymous Parent");
	 }
 }

public class  AnonymousClassDemo{  
	
	public  void method(){
		System.out.println("  before AnonymousClass");
		//����������һ�������࣬���������һ������
		 new AnonymousParent(){ 
			      private int i=1;
			      public void prtI(){
				    System.out.println(i);
			       }
		        }; 
		//�����ඨ��Ľ�β
	   System.out.println("after AnonymousClass ");
	};	

	public static void main(String[] args){
		(new AnonymousClassDemo()).method();
	}
}

