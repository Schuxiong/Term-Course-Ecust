 
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.Calendar;

public class  TestIo2{ 
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
	public static void main(String[] args)  throws Exception{ 
		 
    	 TestIo2.createFile();
		  
	}
}
