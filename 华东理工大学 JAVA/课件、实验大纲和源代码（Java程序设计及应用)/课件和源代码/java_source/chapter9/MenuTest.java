import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

import javax.swing.tree.*;
class  MenuTest extends JFrame{
   DefaultMutableTreeNode root;
   public MenuTest(){
	    JPanel jp=new JPanel();
		jp.setLayout(new FlowLayout());

		getContentPane().add(jp);

        JScrollPane sp=new JScrollPane();
		jp.add(sp);
		
		root=new DefaultMutableTreeNode("father");
		JTree tree=new JTree(root);
		sp.getViewport().add(tree);
		DefaultMutableTreeNode child1=new DefaultMutableTreeNode("child1");
		
		root.add(child1);
        DefaultMutableTreeNode child11=new DefaultMutableTreeNode("child11");
		DefaultMutableTreeNode child12=new DefaultMutableTreeNode("child12");
		DefaultMutableTreeNode child13=new DefaultMutableTreeNode("child13");
       child1.add(child11);
	   child1.add(child12);
	   child1.add(child13);


        DefaultMutableTreeNode child2=new DefaultMutableTreeNode("child2");
		root.add(child1);
        DefaultMutableTreeNode child21=new DefaultMutableTreeNode("child21");
		DefaultMutableTreeNode child22=new DefaultMutableTreeNode("child22");
		DefaultMutableTreeNode child23=new DefaultMutableTreeNode("child23");

       child2.add(child21);
	   child2.add(child22);
	   child2.add(child23);




	   DefaultMutableTreeNode child3=new DefaultMutableTreeNode("child3");
		root.add(child1);
        DefaultMutableTreeNode child31=new DefaultMutableTreeNode("child31");
		DefaultMutableTreeNode child32=new DefaultMutableTreeNode("child32");
		DefaultMutableTreeNode child33=new DefaultMutableTreeNode("child33");

       child3.add(child31);
	   child3.add(child32);
	   child3.add(child33);
	   setSize(200,300);
	   setDefaultCloseOperation(EXIT_ON_CLOSE);

		setVisible(true);
   }



	public static void main(String[] args) 
	{
		 new MenuTest();
	}
}
