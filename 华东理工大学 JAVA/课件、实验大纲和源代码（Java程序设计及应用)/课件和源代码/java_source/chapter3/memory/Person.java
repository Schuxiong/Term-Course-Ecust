 public class  Person{       //��Ա��
    private int No;         //���
	private String name;    //����
	private String sex;    //�Ա�

	public static String school="ECUST";	
	 /*
	public static int k=getK();
	public static int getK(){ System.out.println("getk");return 1;}
	*/
    public Person(){}
	public Person(int No,String name,String sex ){
       this.No=No; this.name=name; this.sex=sex; 
	}
    public void setNo(int No){ this.No=No;}
	public int getNo(){ return No;} 
	public void setName(String name){ this.name=name;}
	public String getName(){return this.name;}
	public void setSex(String sex){this.sex=sex;}
	public String getSex(){return sex;}
	 
	public void speak(){  
	   System.out.println(" ѧУ:"+school+"    ���:"+No+"    ����:"+name+"    �Ա�:"+sex );
	}
}
