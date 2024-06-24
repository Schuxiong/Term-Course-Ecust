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
	  //stu.getAge()是teacher对象发getAge()消息给stu，stu对象通过getAge()响应teacher发送过来的消息。
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
