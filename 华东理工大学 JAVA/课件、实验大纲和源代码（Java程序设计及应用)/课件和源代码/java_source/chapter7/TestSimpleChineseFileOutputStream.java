import java.io.*;
public class TestSimpleChineseFileOutputStream{
	public static void main(String[] args) throws Exception{  
	  byte[] info={97,98,99,100,101,102};  //�ַ�'a'��ASCIIֵΪ97,��������;
	  char[] c={'x','y','z'}; 
	  char[]  ecustChar ={'��','��','��','��','��','ѧ'}; //unicode����
	   
	  try{
		File file=new File("d:/save/TestSimpleChineseFileOutputStream.txt");
		file.createNewFile();
		FileOutputStream outputFile=new FileOutputStream(file);
		
		System.out.println("----------------{97,98,99,100,101,102}--------------" );
		for(int i=0;i<info.length;i++){
		    System.out.print(info[i]);	System.out.print(" ");	
			outputFile.write(info[i]);
		  }
		 System.out.println( );


         System.out.println("------------------{'x','y','z'}---------------" );		
		 for(int i=0;i<c.length;i++){
			 System.out.print(c[i]);	System.out.print(" ");	
			//outputFile.write( c[i]); //д���ֽ� ��ȷ
			//outputFile.write((byte)c[i]); //   ��ȷ
			outputFile.write((int)c[i]); //д���ֽ�  ��ȷ
		  }
		  System.out.println( );


          System.out.println("-----------------{'��','��','��','��','��','ѧ'}---------------" );		
		  for(int i=0;i<ecustChar.length;i++){
			   	
            System.out.print(ecustChar[i]);	System.out.print(" ");	
			outputFile.write(ecustChar[i]); //д���ֵĵ��ֽ� ����
		  }
		  System.out.println( );  
           
		 outputFile.close();
	     } catch(IOException e){System.out.println(e);		         }	    
		 }
	 }