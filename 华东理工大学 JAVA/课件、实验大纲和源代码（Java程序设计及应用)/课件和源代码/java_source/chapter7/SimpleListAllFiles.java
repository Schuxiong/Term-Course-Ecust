import java.io.*;
 import java.util.Calendar;
class  SimpleListAllFiles
{
	public void dir(int level,String str ){
          //str:�ļ��ľ���·��+�ļ���
		  //level:Ŀ¼�Ĳ��

         File file=new File(str);
		 File file2=null;
		 String[] list=file.list();
		 for(int i=0;i<list.length;i++){
              
		   file2=new File(str+"/"+list[i]);
		     
		   if(file2.isFile()){ 
               System.out.println( "�ļ���:"+str+"/"+list[i] ); 
		   }
		   if(file2.isDirectory()){
                 
			      
				 System.out.println( "Ŀ¼��:"+str+"/"+list[i]); 
			  
			    dir(level+1,str+"/"+list[i]);  //�ݹ�

			} 
		 } 
		 return ;
	}

	public  int N(int i){
		int result=1;
		if (i==1)
		{
              result=1;
		}
		if(i>1){
			result=i*N(i-1);
		}
		return result;
	}


	public static void main(String[] args) 
	{
		ListAllFiles all=new ListAllFiles();
		//all.prn("d:\\save");
		all.dir(1,"d:/save/file");
       // System.out.println(all.N(4));
	}
}
