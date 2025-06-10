class  Parent{
	private void privateMethod(){
        System.out.println("Parent privateMethod this:"+this);	
	}
	public void pr1(){	
         privateMethod();
		 System.out.println("Parent pr1 this :"+this);	
		  
	} 
}
public class Child extends Parent{
	public void pr2(){		
		System.out.println("Child pr2 this:"+this);	 
		//System.out.println(super);//语法错误 super不是对象
	}
	public static void main(String[] args) 	{
		 Child c1=new Child();
		 System.out.println(c1);// 打印结果为Child@1x095da
		 c1.pr1();// 打印结果为Child@1x095da
		 c1.pr2();// 打印结果为Child@1x095da:和c1、pr1打印的内容一样
         System.out.println("-----------------------------------" );	 
		 Parent p=new Parent();
		 p.pr1();
	}
}
