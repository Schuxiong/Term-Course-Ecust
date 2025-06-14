package com.lib.login;
 
import javax.swing.*;
import java.awt.BorderLayout; 
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent; 
 
import com.lib.system.MainFrame;
public class  Login{
	JFrame LoginFrame;
	JPanel  LoginPanel;
	JButton ok=null;  //"登录"按钮
	JButton cancel=null;  //"退出"按钮
	JLabel NoLabel=null; // "用户名"标签
	JLabel PasswordLabel=null;// "密码"标签
	JTextField No=null;// "用户名"编辑框
	JTextField Password=null; //"密码"编辑框

	public Login(){
		super();
	}
	public Login(String title){
		LoginFrame=new JFrame();
		LoginPanel=new JPanel();
		NoLabel=new JLabel("用户名");
		PasswordLabel=new JLabel("    密码");
	    
        No= new JTextField(10); 
        Password = new JTextField(10);  

		ok=new JButton("登录");
        cancel=new JButton("退出");      
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

		AddCloseActionListener(); // 加关闭窗口的事件 
		AddCancelClickActionListener(); // 加“退出”按钮的事件
        AddOkActionListener();//加“登录”按钮的事件  
	}
   public void AddCloseActionListener(){
	  LoginFrame.addWindowListener(  //为了关闭窗口
		   new WindowAdapter()   {
               public void windowClosing(WindowEvent e)  {
                   System.exit(0);
               }
           }
	  );
   } 

   public void AddCancelClickActionListener(){
	 cancel.addActionListener(  //为了关闭窗口
	                           //以下new 语句生成一个匿名类
		                       new ActionListener(){
			                     public void actionPerformed(ActionEvent e){
								    Object obj = e.getSource();      
								    if(obj==cancel)  System.exit(0);
								 }//end of actionPerformed
		                        } //end of  new ActionListener()
	                          );// end of cancel.addActionListener
   }

    public void AddOkActionListener(){
	     OkActionClicker  TempOkActionClicker =new OkActionClicker();//生成监听器对象
		 TempOkActionClicker.setLoginFrame(LoginFrame);
		 TempOkActionClicker.setNo(No);
		 TempOkActionClicker.setPassword(Password);
		 ok.addActionListener(TempOkActionClicker);
   }  
    public static void main(String[] args) { 
		Login login=new Login("登录界面"); 
	}
}

//监听器类
class OkActionClicker implements ActionListener {
    JFrame LoginFrame=null;
	JTextField No=null;
	JTextField Password=null;
	public void setLoginFrame(JFrame LoginFrame){
		this.LoginFrame=LoginFrame;
	}
	public void setNo(JTextField No){
		this.No=No;
	}

	public void setPassword(JTextField Password){
		this.Password=Password;
	} 
    
	public void actionPerformed(ActionEvent e){
					 //Object obj = e.getSource();      
					 String no=null;
					 String password=null;
					 no=No.getText(); 
					 password =Password.getText();
					 if( no.equals("1") && password.equals("123")){
						 //  System.out.println("合法用户");
						  MainFrame  TempMainFrame=new MainFrame("系统界面"); 
						  LoginFrame.setVisible(false);
					  }else{
						  System.out.println("非法用户"); 
					  } 
	 } 

	 public static void main(String[] args){
         Login  login=new Login();


	 }
}