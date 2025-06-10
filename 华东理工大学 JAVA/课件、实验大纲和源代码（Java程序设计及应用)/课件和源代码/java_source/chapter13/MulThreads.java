class  Thread1 extends Thread
{
	int i=0;
    public void run(){
	  while(true){
       System.out.println("Thread1 is running"+i);
	   i++;
	   try{
	       sleep(1000);
		  }catch(Exception e){
            System.out.println("errror in thread1");
		  }
	  }
	}	 
}

class  Thread2 extends Thread
{
	int i=0;
    public void run(){
	  while(true){
       System.out.println("Thread2 is running"+i);
	   i++;
	   try{
	       sleep(1000);
		  }catch(Exception e){
            System.out.println("errror in thread1");
		  }
	  }
	}	 
}

public class MulThreads
{
	public static void main(String[] args){
       Thread thread1=new Thread1();
	   Thread thread2=new Thread2();
	   thread1.start();
	   thread2.start();
	}
};