import java.awt.*;
public class TestScrollPanel {    
   public static void main(String[] args){ 
      Frame frame=new Frame("Panel ���Գ���");
      Button ok=new Button("ȷ��");
	  Button cancel=new Button("ȡ��");      
      TextField tf1 = new TextField("Text Field Number 1 "); 
      TextField  tf2 = new TextField("Text Field Number 2 "); 
      Panel p1 = new Panel(); 
      p1.add(ok); 
      p1.add(cancel); 
      p1.add(tf1);
      p1.add(tf2);
      ScrollPane p2 = new ScrollPane(); 
      p2.add(p1); 
      frame.add(p2);         
      frame.setBounds( 100, 100, 300, 300); 
      frame.setVisible(true);        
   } 
} 

