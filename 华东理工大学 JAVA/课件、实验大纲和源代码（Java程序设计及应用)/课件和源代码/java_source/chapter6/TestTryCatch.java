public class TestTryCatch{
    public static void main(String[] args){
        int i=1;
        int j=0;
        try{
			System.out.println("try block entered");
			System.out.println(i/j);  //����ArithmeticException�쳣
			System.out.println("Ending try block");
		}catch(ArithmeticException e){
                  System.out.println("Arithmetic Exception caugth");
                }
         System.out.println("After try block");
		 }
	   }   
