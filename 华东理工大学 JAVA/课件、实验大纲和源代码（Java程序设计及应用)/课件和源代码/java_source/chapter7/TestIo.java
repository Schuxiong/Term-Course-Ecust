
import java.io.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Calendar;

public class  TestIo{
    
	//����16���Ʒ�ʽ��ʾstr��encoding�����ʽ
	public static void Encode(String encoding,String str)throws Exception { 
        byte[] bytes=str.getBytes(encoding);//GBKΪWindowsϵͳĬ�ϱ����ı��ļ��ı����ʽ
		System.out.print(""+str+" "+encoding+": ");
		for(int i=0;i<bytes.length;i++){
			System.out.printf(" %x",(bytes[i]));
		} 
		System.out.println( );
	}
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


    //���ַ���unicodeStr��"��������ѧecust"���浽d:/save/a/ecust.txt�ļ��� 
	public static void createFile() throws Exception{  
         String file="d:/save/a/ecust.txt";
		String unicodeStr="��������ѧecust";//�ַ�������Unicode�����ʽ�����ڴ��еġ���UTF-16 �� UTF-16BE ��ʽ)
		byte[] unicodeBytes=unicodeStr.getBytes("GBK");//GBKΪWindowsϵͳĬ�ϱ����ı��ļ��ı����ʽ
		File ecust=new File(file);
		ecust.createNewFile();
        FileOutputStream outputStream=new FileOutputStream(ecust);
		for(int i=0;i<unicodeBytes.length;i++){
			outputStream.write(unicodeBytes[i]);
		}
		outputStream.close();

	}

	//��d:/save/a/ecust.txt�ļ��е��ַ���ȡ��unicodeStr������ 
	public static void readFile() throws Exception{  
        String file="d:/save/a/ecust.txt";
		String unicodeStr= null;//�ַ�������Unicode�����ʽ�����ڴ��еġ���UTF-16 �� UTF-16BE ��ʽ)
		byte[] unicodeBytes=null;//�����ȡ�ļ����ֽ����ݡ���GBKΪWindowsϵͳĬ�ϱ����ı��ļ��ı����ʽ��
		File ecust=new File(file); 
		int filesize=(int)ecust.length();//�ļ��ֽڴ�С
        unicodeBytes=new byte[filesize];

		
        FileInputStream inputStream=new FileInputStream(ecust);
		int i=0;
		int content=0;//����ÿ�ζ�ȡ�ļ���һ���ֽ�����
		while((content=inputStream.read())!=-1){
  
           unicodeBytes[i]=(byte)content;//����ȡ�����ֽ����ݱ��浽������
		   i++;

		}

		unicodeStr=new String(unicodeBytes,"GBK");//����"GBK"�����ʽת��unicodeBytes�ֽ������е�������String
		// public String(byte bytes[], Charset charset)
		System.out.println("["+unicodeStr+"]");
		inputStream.close();

	}


    //��d:/save/a/ecust.txt�ļ����Ƶ�d:/save/b/ecust.txt�� 
	public static void copyFile() throws Exception {  
        String sourcefile="d:/save/a/ecust.txt"; 
		String destinationfile="d:/save/b/ecust.txt"; 
		 
		File source=new File(sourcefile);
		File destination=new File(destinationfile);
		destination.createNewFile();
        FileInputStream sourceStream=new FileInputStream(source);
		FileOutputStream destinationStream=new FileOutputStream(destination);
		int content=0;
		while((content=sourceStream.read())!=-1){

           destinationStream.write(content);

		}
		sourceStream.close();
		destinationStream.close(); 
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
		 //����3��������Կ���Unicode�����������ֽڱ�ʾ�ַ�����GBK������һ���ֽڱ�ʾ�ַ��������ֽڱ�ʾ����
		
		 TestIo.Encode("Unicode","abc");
		 TestIo.Encode("Ascii","abc");
		 TestIo.Encode("GBK","abc");


         //����3��������Կ���Unicode�����������ֽڱ�ʾ�ַ�,����
		 //��GBK������һ���ֽڱ�ʾ�ַ��������ֽڱ�ʾ���� 
		 TestIo.Encode("Unicode","abc��������ѧecust");
		 TestIo.Encode("UTF-16BE","abc��������ѧecust"); //���Կ���Unicode����ʵ���ǲ���UTF-16BE�����ʽ+BOMͷ��fe ff)
         TestIo.Encode("UTF-8","abc��������ѧecust"); 
		 TestIo.Encode("GBK","abc��������ѧecust");
		 
		 TestIo.createDirectory();
		 TestIo.createFile();
		 TestIo.copyFile(); 
		 TestIo.readFile();
		 TestIo.dir(1,"d:/save/a"); 
	}
}
