import java.io.*; 
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Calendar;

public class  TestIo1{ 
	 
	//��d:/saveĿ¼�´���a,b��Ŀ¼
	//��d:/save/aĿ¼�´���c��Ŀ¼
	public static void createDirectory() throws Exception{  
		String directory="d:/save";
		String aDirectory="d:/save/a";
		String bDirectory="d:/save/b";
		String cDirectory="d:/save/a/c";
		File a=new File(aDirectory);
		File b=new File(bDirectory);
		File c=new File(cDirectory);
		a.mkdir();
		b.mkdir();
		c.mkdir(); 
	} 
    public static void createFile() throws Exception{  
         String file="d:/save/a/ecust.txt";
		 File ecust=new File(file);
		ecust.createNewFile(); 
	} 
     
  //�ݹ鷽ʽ��ʾdirectoryĿ¼�����е��ļ�����Ŀ¼
	public static void dir(int level ,String directory){ 
        //directory:�ļ��ľ���·��+�ļ���
	    //level:Ŀ¼�Ĳ��

         File file=new File(directory);
		 File file2=null;
		 String[] list=file.list();
		 for(int i=0;i<list.length;i++){ 
		   file2=new File(directory+"/"+list[i]); 
		   if(file2.isFile()){ 
              //���´������"-",�Ա���ʾ������
			 String filename="";
			 for(int t=1;t<=level;t++){
				 filename+="-";
			 }
			 filename+=list[i] ;
			  System.out.println( "�ļ���:"+filename );  
		   }
		   if(file2.isDirectory()){
                //System.out.println("ʱ�䣺"+cd.getTime()+"Ŀ¼��:"+list[i]); 
				String directory2="";
			    for(int t=1;t<=level;t++){
				     directory2+="-";
			    }
			    directory2+=list[i] ; 
				System.out.println( "Ŀ¼��:"+directory2); 

			    dir(level+1,directory +"/"+list[i]);  //�ݹ� 
			} 
		 } 
		 return ;

	}
	public static void main(String[] args)  throws Exception
	{ 
		   
		 TestIo1.createDirectory();
		 TestIo1.createFile();
		  
		 TestIo1.dir(1,"d:/save/a"); 
	}
}
