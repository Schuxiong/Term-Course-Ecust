class  SuperStar{
        String name;
        int age;
	   
        int getAge(){ 		  
		  //return age;  
		  int tempAge=makeUp(40);//��ױ�������
		  return tempAge;
	   }
	    void setAge(int age2){  
		  age=age2; 
	  }
	    int makeUp(int age2){	//��ױ	   
		  return  age2;
	  }
}

public class TestSuperStar3{
	public static void main(String[] args){
      SuperStar chenglong=new SuperStar(); //����
	  chenglong.setAge(60);
	  int age2=chenglong.getAge();
	  System.out.println(age2);  //40
      System.out.println(chenglong.age);  //60 
	}
}


