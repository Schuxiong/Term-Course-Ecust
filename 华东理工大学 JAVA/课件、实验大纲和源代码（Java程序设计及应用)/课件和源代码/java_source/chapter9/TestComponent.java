import java.awt.*;
import javax.swing.*;
public class TestComponent extends Frame{    
    TestComponent(String title){
		super(title);
		JLabel prompt1=new JLabel("����");
		JLabel prompt2=new JLabel("�Ա�");
		JLabel prompt3=new JLabel("���˰���");
		JTextField name=new JTextField(10);
		 ButtonGroup group=new ButtonGroup();
		JCheckBox  check1=new JCheckBox("��" );
        JCheckBox  check2=new JCheckBox("Ů" );
		group.add(check1);
		group.add(check2);
        
		JCheckBox  check3=new JCheckBox("����");
        JCheckBox  check4=new JCheckBox("�ﾶ");
        JCheckBox  check5=new JCheckBox("��Ӿ");

		setLayout(new FlowLayout());
        add(prompt1);add(name);
		add(prompt2);add(check1);add(check2);
		add(prompt3);add(check3);add(check4);add(check5);
		setBounds( 100, 100, 300, 300); 
		setVisible(true);
	}
	public static void main(String[] args){ 
     new TestComponent("Swing������Գ���"); 
   } 
} 

