
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.util.Random;
import java.io.RandomAccessFile;


//�ⲿ����:������������.
//���ݱ�������棬����Ĺ����У�ֻ������Ҫ���ŵ����ݺ���Ҫ�Ƚϵ����ݣ����������ݲ����뵽�ڴ档
//ÿ�������ʱ��ֻ������int����
public class  DiskSort
{
	//�������10�����������浽�ļ�d:/save/data.dat��
	public static void saveData() throws Exception{

        File file=new File("d:/save/data.dat");
		file.createNewFile();
		int randomInt=0;
		int[] data=new int[10];//�������10������ 
		Random random=new Random();
		for(int i=0;i<data.length;i++){ 
          randomInt=random.nextInt()%100;
		  data[i]=randomInt; 
		} 
        FileOutputStream fileoutput=new FileOutputStream(file);
        DataOutputStream output=new DataOutputStream(fileoutput);
		for(int i=0;i<data.length;i++){ 
		   output.writeInt(data[i]);// ��10���������浽�ļ�d:/save/data.dat��
		} 
		output.close(); 
	}

    // ��ӡ�ļ�d:/save/data.dat�е�����
	public static void printData() throws Exception{

        File file=new File("d:/save/data.dat"); 
		long fileSize=file.length();
		int[] data=new int[(int)fileSize/4];
		 
        FileInputStream fileInput=new FileInputStream(file);
        DataInputStream input=new DataInputStream(fileInput);
		for(int i=0;i<data.length;i++){ 
		   data[i]=input.readInt();
		}
		for(int i=0;i<data.length;i++){ 
          System.out.print(data[i]);System.out.print(" ");
		}
		System.out.println( );
		input.close();

	}


    // ���ļ�d:/save/data.dat�е����ݽ����ⲿ����
	public static void sortData() throws Exception{

        File file=new File("d:/save/data.dat"); 
		long fileSize=file.length();
		int[] data=new int[(int)fileSize/4];
		 
        //FileInputStream fileInput=new FileInputStream(file);
        //DataInputStream input=new DataInputStream(fileInput);
		RandomAccessFile random=new RandomAccessFile(file,"rw");
		 
		int currentInt=0;
		int nextInt=0;
		int tempInt=0;
		for(int i=0;i<data.length;i++){ 
		   random.seek(i*4);
		   currentInt=random.readInt();
		    
           for(int j=(i+1);j<data.length;j++){
               random.seek(j*4);
			   nextInt=random.readInt(); 

			   if(nextInt>currentInt){
                 tempInt=currentInt;
				 random.seek(i*4);
				 random.writeInt(nextInt);
				 random.seek(j*4);
				 random.writeInt(tempInt);  
                 currentInt=nextInt;
			   } 
		   }
		   
		    currentInt=0;
		    nextInt=0;  
		}
		 
		random.close();

	}
	public static void main(String[] args) throws Exception
	{
         
		 DiskSort.saveData();
		 System.out.println(" ����ǰ������");
		 printData();
		 

		 sortData();//�ⲿ����
		 System.out.println(" ����������");
		 printData();
	}
}
