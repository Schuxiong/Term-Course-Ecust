class Employee{
  String name;  int employeeNo ;
  private static int id=0;
  Employee(String sName){
    employeeNo=++id;   name=sName;
  }   
  public static int getAllEmployee(){
	 //System.out.println(name); ����������ܷ���ʵ������
     return id;
  }
}

public class StaticMethodTest{
   public static void main(String[]  args){
    Employee zhang=new Employee("zhang");
    Employee wang=new Employee("wang");
     System.out.println(zhang. getAllEmployee ());
     System.out.println(wang. getAllEmployee ());
     System.out.println(Employee. getAllEmployee ());
   }
}
