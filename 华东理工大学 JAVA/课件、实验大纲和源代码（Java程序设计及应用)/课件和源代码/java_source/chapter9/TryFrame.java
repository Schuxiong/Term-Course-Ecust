 import java.awt.*;
 public class TryFrame extends Frame{
      TryFrame(String str){
         super(str);
	Button ok=new Button("ȷ��");
	Button cancel=new Button("ȡ��");
	setLayout(new FlowLayout());
	add(ok);
	add(cancel);
        setBounds( 100, 100, 500, 500);  //setSize(200,100);	
        setVisible(true); 	//show();
	}
       public static void main(String[] args){
	  new TryFrame("Frame ���Գ���");
	}
}
