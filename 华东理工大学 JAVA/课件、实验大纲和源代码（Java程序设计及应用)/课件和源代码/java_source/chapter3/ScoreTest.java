class ScoreClass{
  int No;
  int score;
 
  ScoreClass(){
  }
  ScoreClass(int n,int s){
   No=n;    score=s;
  }

  void setNo(int n){     No=n;  }
  int  getNo(){   return No;  }

  void setScore(int s){     score=s;  }  
  int  getScore(){   return score;  }
}
 
 public class ScoreTest{
   public static void main(String[] args){
      ScoreClass student1=new ScoreClass(1,100);
      ScoreClass student2=new ScoreClass();

      student2.setNo(2);
      student2.setScore(90);

      System.out.println(student1.getNo()); 
	  System.out.println(student1.No); ����//���������������һ��

      System.out.println(student1.getScore()); 
	  System.out.println(student1.score);��//���������������һ��

      System.out.println(student2.getNo());
      System.out.println(student2.getScore());
   }
 }
       