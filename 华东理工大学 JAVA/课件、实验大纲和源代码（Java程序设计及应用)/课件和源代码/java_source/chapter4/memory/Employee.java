public class Employee{
  private String name;  
  private int No ;

  private String address=setAddress();

  public static int id=setId();
  public static String country=setCountry();
  

 
  public  final static int k=33;
   
  public Employee(){
     System.out.println(" �����췽��: public Employee()");
  }
  public Employee(String sName){
    No=++id;   name=sName;
  }
  
  public void setName(String name){ this.name=name;}
  public String getName(){return name;} 

  public void setNo(int No){ this.No=No;}
  public int getNo(){return No;} 

  public String toString(){ 
	  return " name:"+name+" No:"+No+" id:"+id;
  }

  public static int setId(){
      System.out.println(" ��ʼ���������static int id=0");
	  return 0;
  }
  public static String setCountry(){
      System.out.println(" ��ʼ���������static int country='china'");
	  return "china";
  }

  public String setAddress(){

       System.out.println(" ��ʼ��ʵ�������� private String address='shanghai'");
	   return "shanghai";
  }

}
