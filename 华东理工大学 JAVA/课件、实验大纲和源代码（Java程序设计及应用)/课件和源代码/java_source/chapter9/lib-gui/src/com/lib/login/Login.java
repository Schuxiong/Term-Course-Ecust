package com.lib.login; 
import javax.swing.*;
import java.awt.BorderLayout; 
import com.lib.system.MainFrame;
//���³��������һ��ͼ���û����棬���¼�����
public class  Login{
	JFrame LoginFrame;//��������
	JPanel  LoginPanel;//JPanel�����ڶ�������LoginFrame��
	JButton ok=null;  //"��¼"��ť
	JButton cancel=null;  //"�˳�"��ť
	JLabel NoLabel=null;  // "�û���"��ǩ
	JLabel PasswordLabel=null; // "����"��ǩ
	JTextField No=null;    // "�û���"�༭��
	JTextField Password=null; //"����"�༭�� 
	public Login(){		super();	}

	public Login(String title){
		LoginFrame=new JFrame();
		LoginPanel=new JPanel();
		NoLabel=new JLabel("�û���");
		PasswordLabel=new JLabel("    ����");
	    
        No= new JTextField(10); 
        Password = new JTextField(10);  
		ok=new JButton("��¼");
        cancel=new JButton("�˳�");      

		LoginPanel.add(NoLabel  ); 
		LoginPanel.add(No  ); 
		LoginPanel.add(PasswordLabel  ); 
		LoginPanel.add(Password  ); 
		LoginPanel.add(ok  ); 
		LoginPanel.add(cancel  ); 

		BorderLayout LoginFrameLayout=new BorderLayout(); 
		LoginFrame.setLayout(LoginFrameLayout);
		LoginFrame.setTitle(title);
		LoginFrame.add("Center", LoginPanel ); 
		LoginFrame.setBounds(600,300,200,200); 
        LoginFrame.setVisible(true); 
	} 
   
	public static void main(String[] args) { 
		Login login=new Login("��¼����");		 
	}
}

 