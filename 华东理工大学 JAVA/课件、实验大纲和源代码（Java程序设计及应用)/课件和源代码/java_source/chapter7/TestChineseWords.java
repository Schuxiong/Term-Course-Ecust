import java.io.*;
class  TestChineseWords
{
	public static void main(String[] args) throws Exception
	{
		String str1="����"; 
		String str2="a����b";
		String str3="a��b��1";
		String str4="cdef1234";

		System.out.println(str1.length());
		System.out.println(str2.length());
		System.out.println(str3.length());
		System.out.println(str4.length());

		 

		 byte[] b1=str1.getBytes("GBK");//��Unicode�����ʾ��str1����GBK����ת��
		 byte[] b2=str2.getBytes();//��Unicode�����ʾ��str2����WindowsϵͳĬ�ϵı��루GBK��ת��
		 byte[] b3=str3.getBytes("GBK"); 
		 byte[] b4=str4.getBytes("GBK");
		 
         byte[] b11=str1.getBytes("utf-8");//��Unicode�����ʾ��str1����GBK����ת��
		
		 //str1��GBK����
		 System.out.print (str1+" GBK����:   ");
		 for(int i=0;i<b1.length;i++){ 
			//System.out.print( "  "+b1[i]);
			System.out.printf( " %x",b1[i]);//��16�������
		 } 
		 System.out.println();
		 //System.out.println(b1.length);


		 //str1��utf-8����
		 for(int i=0;i<b11.length;i++){ 
			//System.out.print( "  %x"+b11[i]);
			//System.out.printf( " %x",b11[i]);//��16�������
		 }
		 System.out.println();

         //str2��GBK����
		 System.out.print (str2+" GBK����: ");
		 for(int i=0;i<b2.length;i++){ 
			//System.out.print(  " "+ b2[i]);
			System.out.printf( " %x",b2[i]);//��16�������
		 }
		 
		 System.out.println();
		// System.out.println(b2.length);

          //str3��GBK����
		  System.out.print (str3+" GBK����:");
		 for(int i=0;i<b3.length;i++){ 
			//System.out.print(  " "+ b3[i]);
			System.out.printf( " %x",b3[i]);//��16�������
		 }
		 
		 System.out.println();
		// System.out.println(b3.length);


          //str4��GBK����
		 System.out.print (str4+"GBK����:");
		 for(int i=0;i<b4.length;i++){ 
			//System.out.print( " "+  b4[i]);
			System.out.printf( " %x",b4[i]);//��16�������
		 }
		 
		 System.out.println();
		 //System.out.println(b4.length);

         int k='��'; 
		 String s=Integer.toHexString(k);//10����ת����16����
		 System.out.println("��  int: "+k+"   unicode: "+s );
		 System.out.println('\u534e' );
		 System.out.printf("%x",k );
		 System.out.println(  ); 

		 int unicode1=0x53;  //'��'��unicode����ĸ��ֽ�
		 int unicode2=0x4e;  //'��'��unicode����ĵ��ֽ�
         System.out.println(""+unicode1+" "+unicode2 ); 


		 int a='a'; 
		 String s2=Integer.toHexString(a);//10����ת����16����
		 System.out.println("a  int: "+a+"   unicode: "+s2 );
		// System.out.println('\u534e' );
		 System.out.printf("%x",a );
		 System.out.println(  ); 
		  

         
          FileOutputStream file=new FileOutputStream("chinese.txt");
		
		 file.write(unicode1); //'��'��unicode����ĸ��ֽ�
		 file.write(unicode2); //'��'��unicode����ĵ��ֽ�

		 int c1=0xbb;//'��'��GBK����ĸ��ֽ�
		 int c2=0xaa;//'��'��GBK����ĵ��ֽ� 
		 file.write(c1);//'��'��GBK����ĸ��ֽ�
		 file.write(c2);//'��'��GBK����ĵ��ֽ� 

		  
		 for(int i=0;i<b1.length;i++){ 
            file.write(b1[i]);
			System.out.print  (b1[i]);
			System.out.print  (" ");
		 }
		 System.out.println(  ); 


		 for(int i=0;i<b2.length;i++){
            System.out.print  (b2[i]);
			System.out.print  (" ");
		 }
		 System.out.println(  ); 


		 for(int i=0;i<b3.length;i++){
            System.out.print  (b3[i]);
			System.out.print  (" ");
		 }
		 System.out.println(  ); 

		 
	}
}
