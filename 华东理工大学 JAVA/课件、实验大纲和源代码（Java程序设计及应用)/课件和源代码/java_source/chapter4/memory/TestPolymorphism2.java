
public class   TestPolymorphism2{
	public static void main(String[] args)	{
		Person p=null;
		Teacher tom=new Teacher( 1,"tom","��","�����ϵ","����",6000); 
		Student rose=new Student(11,"rose","Ů","�����",600);
		
		p=tom;
        p.speak(); 
		p=rose;
        p.speak(); 
	}
}



 
