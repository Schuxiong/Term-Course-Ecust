//file name��TryFlowLayout.java
import java.awt.*;
import javax.swing.*;
public class TryFlowLayout extends JFrame   {  //���㴰����
	JButton[] button = new JButton[9];  //����9����ť�����
	FlowLayout layout;    //�������ֹ���������
	public TryFlowLayout()  {  
        super("FlowLayout Ӧ�þ���");  //���ö��㴰�ڱ���
        String label;   
        
	    //�������ֹ���������    
        layout = new FlowLayout(FlowLayout.LEFT,10,10);   
        getContentPane().setLayout(layout);      //���ò��ֹ�����
        	
        for (int i = 0; i < 9; i++) {               //����9����ť������ӵ�������
           	label = "Button #" + ( i + 1 ) + " ";
		button[i] = new JButton(label);
		getContentPane().add(button[i]);
         }
         setSize(320,160);                 	//����ʾ��������Ϊ320��160
         setVisible(true);		//��ʾ����
         setResizable(false);               	//�ô��ڲ��ܵ��ڴ�С
	}
	public static void main(String[] args){
	    TryFlowLayout frame = new TryFlowLayout();   //�������㴰�ڶ���
	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

