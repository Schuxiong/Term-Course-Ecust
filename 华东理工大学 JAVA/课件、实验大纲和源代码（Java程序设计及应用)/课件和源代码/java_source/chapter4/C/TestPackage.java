//C���е�TestPackage.java
package C;    //����C��,����TestPackage.class����C��   
                       // �����ռ���
import A.*;          //����A��
import B.*;          //����B��

public class  TestPackage{
  public static void main(String[] args){
     A.T1  at1=new A.T1();
     B.T1  bt1=new B.T1();
     T2    t2=new T2();
     at1.p1();
     bt1.p1();
     bt1.p2();
     t2.p1();      
     }
}
