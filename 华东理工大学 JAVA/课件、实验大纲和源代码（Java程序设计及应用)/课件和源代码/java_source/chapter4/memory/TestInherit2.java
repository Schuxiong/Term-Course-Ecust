public class   TestInherit2
{
	public static void main(String[] args) 
	{
		Teacher tom=new Teacher( 1,"tom","��","�����ϵ","����",6000); 
        tom.speak();
        

 	
	 

       // Teacher jack=new Teacher( 1,"jack","��","�����ϵ","����",6000); 
        Teacher jack=new Teacher(  ); 
		jack.setNo(1);       //�̳и���ķ���
		jack.setName("jack");   //�̳и���ķ���
		jack.setSex("��");   //�̳и���ķ���
		jack.setDepartment("�����ϵ");
		jack.setTitle("����");
		jack.setSalary(6000); 
        System.out.println("��ʦ: "+"  ѧУ:"+Person.school+"    ���:"+jack.getNo()+"    ����:"+jack.getName()+"    �Ա�:"+jack.getSex()+" ���ڲ���:"+jack.getDepartment()+"  ְ��: "+jack.getTitle()+" ����:"+jack.getSalary() );
		  //Person.school: �̳и���ĳ�Ա����

     //   jack.school="fudan";

		//Person p1=new Person();
       // System.out.println( "  ѧУ:"+Person.school);

		//System.out.println(tom.equals(tom));
	}
}
