class Ticket{
	public int num=0;
	public Ticket(int num){this.num=num;}
}

class Booking1 implements Runnable{ 
	public Ticket ticket=null; 
	public Object synchronizedObject=null;
	public Booking1( ){ 		} 
	public void run(){ 
		int temNum=0;
		// System.out.println("this object:"+this);
		synchronized(synchronizedObject){   //对象同步 （锁)
			 System.out.println("this object:"+this+"  synchronizedObject:"+synchronizedObject+" sleep begin:"); 

			 temNum=ticket.num;
		      
		     try{  
		         Thread.sleep(100 );
		        }catch(Exception e){
		         }

			 ticket.num=temNum-1;

			 System.out.println("this object:"+this+"  synchronizedObject:"+synchronizedObject+" sleep end"); 
		}
	}
}

class Booking2 implements Runnable{ 
	public Ticket ticket=null; 
	public Object synchronizedObject=null;
	public Booking2( ){ 		} 
	public void run(){ 
		int temNum=0;
		//System.out.println("this object:"+this);
		synchronized(synchronizedObject){   //对象同步 （锁)
			// System.out.println("this object:"+this+"  synchronizedObject:"+synchronizedObject+" sleep begin:"); 

			 temNum=ticket.num;
		      
		     try{  
		         Thread.sleep(100 );
		        }catch(Exception e){
		         }

			 ticket.num=temNum-1;

			//System.out.println("this object:"+this+"  synchronizedObject:"+synchronizedObject+" sleep end"); 
		}
	}
}

public class  TestThread33{
	public static void main(String[] args)	{	
	   Ticket ticket=new Ticket(10000); 
       Object synchronizedObject=new Object();
	    
		 

	   
       for(int i=0;i<=8 ;i++){
           
	      Booking1 booking1=new Booking1( ); 
		  booking1.ticket=ticket; //共享数据
		  booking1.synchronizedObject=synchronizedObject; 
          Thread thread1=new Thread(booking1,"thread1");
	      thread1.start();

	   }

	   try{  
		         Thread.sleep(3000 );
		        }catch(Exception e){
		         }

				 /*
	   try{
		   thread1.join();
		   thread2.join();
	   }catch(Exception e){
	   }
	   */
	      
	  // System.out.println("booking1.ticket.num: "+booking1.ticket.num);
	  // System.out.println("booking2.ticket.num: "+booking2.ticket.num);
	   System.out.println( "ticket.num: "+ticket.num);
	  
	}
}
