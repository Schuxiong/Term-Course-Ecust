class Person{
	public String name;//����
	public String Id; //���֤ 
	private int   age;  //���� ��˽������

	public Person(){	}
	public Person(String name,String Id, int age){	
	    this.name=name; this.Id=Id;  this.age=age;
	}
    
	public void setName(String name){ this.name=name;}
	public String getName(){return name;}

	public void setId(String Id){ this.Id=Id;}
	public String getId(){return Id;}

	public void setAge(int age){ this.age=age;}
	public int getAge(){return age;} 

	public String toString(){return "Person��";}
}

public class  Student  extends Person{
	public String no;//ѧ��
	public String school; //ѧУ 
    
	public Student(){	}
	public Student(String name,String Id, int age,
		String no,String school ){	
	    this.name=name; this.Id=Id;  setAge(age);
		this.no=no;this.school=school; 
	}

	public void setNo(String no){ this.no=no;}
	public String getNo(){return no;}

	public void setSchool(String school){ this.school=school;}
	public String getSchool(){return school;}

    //overriding
    public String toString(){return "Student��";}

	public static void main(String[] args) 	{
		String  name=null; 
		String id=null;
		int     age=0;  

		Student rose=new Student(); 
		 rose.setName("rose");  //����ķ���
		 rose.setId("3300"); //����ķ���
		 rose.setAge(20);  //����ķ���
		 rose.setNo("2006");  
		 rose.setSchool("Ecust");

		  age=rose.getAge();
		  name=rose.getName(); 
		  id=rose.getId();

		System.out.println( age);
		System.out.println( name);
		System.out.println( id); 

	}
}
