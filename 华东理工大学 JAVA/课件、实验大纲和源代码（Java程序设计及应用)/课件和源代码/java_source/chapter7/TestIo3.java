
import java.io.*;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Calendar;

public class  TestIo3{ 

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

 
	public static void main(String[] args)  throws Exception
	{ 
		 
		 TestIo.copyFile(); 
		 TestIo.readFile();
		 
	}
}
