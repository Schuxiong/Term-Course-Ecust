import java.io.*;
 import java.util.Calendar;
class  ListAllFiles
{
	public void dir(int level,String str ){
          //str:�ļ��ľ���·��+�ļ���
		  //level:Ŀ¼�Ĳ��

         File file=new File(str);
		 File file2=null;
		 String[] list=file.list();
		 for(int i=0;i<list.length;i++){
              
		   file2=new File(str+"/"+list[i]);
		     Long time =file.lastModified();        
			 Calendar cd = Calendar.getInstance();        
			 cd.setTimeInMillis(time);        
			   

		   if(file2.isFile()){ 
             //  System.out.println("ʱ�䣺"+cd.getTime()+" �ļ���:"+list[i]+" ��С:"+file2.length()); 
		     //���´������"-",�Ա���ʾ������
			 String str2="";
			 for(int t=1;t<=level;t++){
				 str2+="-";
			 }
			 str2+=list[i] ;
			  System.out.println( "�ļ���:"+str2 ); 
		 
		   }
		   if(file2.isDirectory()){
                //System.out.println("ʱ�䣺"+cd.getTime()+"Ŀ¼��:"+list[i]); 
				String str2="";
			    for(int t=1;t<=level;t++){
				 str2+="-";
			     }
			    str2+=list[i] ;
			      
				 System.out.println( "Ŀ¼��:"+str2); 
			  
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
		all.dir(1,"d:/save/Library-ejb");
       // System.out.println(all.N(4));
	}
}
