import java.io.*;

/**

 * ʹ��FileOutputStreamд�ļ�ʾ��

 */

public class WriteFile1 {

         public static void main(String[] args) {

                   String s = "Java����";

                   int n = 100;

                   //����������

                   FileOutputStream fos = null;

                   try{

                            //����������

                            fos = new FileOutputStream("d:\\save\\out.txt");

                            //ת��Ϊbyte����

                            byte[] b1 = s.getBytes();

                            //���з�

                            byte[] b2 = "\r\n".getBytes();

                            byte[] b3 = String.valueOf(n).getBytes();

                            //����д���ļ�

                            fos.write(b1);

                            fos.write(b2);

                            fos.write(b3);

                   } catch (Exception e) {

                            e.printStackTrace();

                   }finally{

                            try{

                                     fos.close();

                            }catch(Exception e){}

                   }

         }

}
