 class Student{

	private int age=0;
	public void setAge(int tempAge){
		age=tempAge;
	}
	public int getAge(){
		return age;
	} 
}

class Teacher {
	public void tellMeYourAge(Student stu){ 
      System.out.println("  tellMeYourAge:"+ stu.getAge()); 
	  //stu.getAge()��teacher����getAge()��Ϣ��stu��stu����ͨ��getAge()��Ӧteacher���͹�������Ϣ��
	}
}

public class TestMessage{

	public static void main(String[] args){
		 
		Student zhang=new Student();
		zhang.setAge(1);

        Teacher  wang=new Teacher();
		wang.tellMeYourAge(zhang); 
		 
	}
}
