 
public class  Student extends Person    //ѧ����
{ 
	private String major;  //רҵ
	private int score  ;    //�߿��ɼ�

	public Student(){} 
	public Student(int No,String name,String sex,String major, int score ){
	  // super( No, name, sex);
	   setNo(No);setName(name);setSex(sex); 
       this.major=major;   this.score=score; 
	}
    public void setMajor(String major){ this.major=major;}
	public String getMajor(){ return major;} 

	 

	public void setScore(int score){this.score=score;}
	public int getScore(){return this.score;}
	 
	public void speak(){  
	   System.out.println("ѧ��: "+"  ѧУ:"+school+"    ���:"+getNo()+"    ����:"+getName()+"    �Ա�:"+getSex()+" ����רҵ:"+getMajor()+ " �߿��ɼ�:"+getScore() );
	}
}
