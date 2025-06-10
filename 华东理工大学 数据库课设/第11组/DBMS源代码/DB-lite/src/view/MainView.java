package view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import bean.StatementType;
import create.FileMgr;
import utils.Block;
import utils.Page;
import utils.User;
import javax.imageio.ImageIO;
import java.io.File;
import java.io.IOException;
import java.awt.Image;
import java.awt.Graphics;


public class MainView extends JFrame {
	private static final long serialVersionUID = 1L;

	User u1 = new User();
	JPanel pan = new JPanel(null);
	JLabel greet = new JLabel("DBMS-lite");
	JLabel SQLText = new JLabel("input your SQL");
	JTextField SQLState = new JTextField();
	JTextArea textArea = new JTextArea();
	JTextArea log = new JTextArea();
	Font font1 = new Font("Yahei", Font.BOLD, 48);
	Font font2 = new Font("Yahei", Font.BOLD, 20);
	JScrollPane jsp = new JScrollPane(textArea, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
			JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
	JScrollPane jspLog = new JScrollPane(log, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
			JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

	public MainView(User u1) {
		this.u1 = u1;
		this.init();

//		System.out.println(u1.toString());
	}

	public void init() {
		BufferedImage iconImg = null;
		try {
			iconImg = ImageIO.read(new File("img/icon1.png"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		this.setSize(600, 500);
		this.setResizable(true);
		this.setTitle("USE DBMS-lite");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLocationRelativeTo(null);
		this.setContentPane(new MainView.BackgroundPanel()); // 设置背景
		pan.setOpaque(false);
		this.setIconImage(iconImg);
		this.addPart();
		this.listen();
		this.pack();
		this.setVisible(true);
	}
	private class BackgroundPanel extends JPanel {
		private BufferedImage backgroundImg;

		public BackgroundPanel() {
			try {
				backgroundImg = ImageIO.read(new File("img/background2.png")); // 背景图像的文件路径
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			if (backgroundImg != null) {
				g.drawImage(backgroundImg, 0, 0, getWidth(), getHeight(), this);


			}
		}
	}

	public void addPart() {

		pan.setPreferredSize(new Dimension(600, 500));

		greet.setBounds(25, 15, 450, 45);
		greet.setFont(font1);
		pan.add(greet);

		SQLText.setBounds(25, 90, 150, 30);
		SQLText.setFont(font2);
		pan.add(SQLText);

		SQLState.setBounds(180, 90, 350, 30);
		SQLState.setFont(font2);
		pan.add(SQLState);

		jsp.setBounds(30, 150, 540, 280);
		jsp.setFont(font2);
		pan.add(jsp);
		jspLog.setBounds(30, 440, 540, 50);
		jspLog.setFont(font2);
		pan.add(jspLog);


		this.add(pan);
	}

	public void listen() {
		Font newFont = new Font("SansSerif", Font.PLAIN, 16);
		textArea.setFont(newFont); // 设置textArea的字体

		SQLState.addKeyListener(new KeyAdapter() {
			@Override
			public void keyReleased(KeyEvent e) {
				int keyCode = e.getKeyCode();
				if (keyCode == KeyEvent.VK_ENTER) {
//					textArea.append(SQLState.getText() + "\r\n");
					String sqlState = SQLState.getText();
					sqlState = sqlState.toLowerCase();
					User u2 = new StatementType().getStatementType(sqlState, u1);
					String logs = u2.getLogs();
					if(logs.contains("Error")) {
						textArea.setText(logs.split("~")[0]);
						log.setText(logs.split("~")[1]);
					}else if(logs.contains("OK")) {
						if(sqlState.contains("select")) {
							textArea.setText(u2.getSelectResult());
						}else {
							textArea.setText(logs.split("~")[0]);
						}
						log.setText(logs.split("~")[1]);
					}
					
					if(!("".equals(sqlState.split(" ")[0]))) {
//						result = new StatementType().get;
					}
					//向当前日志写入内容
					System.out.println(u1.getLogFileName());
					
					if(u1.getUseDB()!=null && u1.getLogFileName()!=null) {

						int npos = Page.maxLength( u1.getLogs().length());
						byte[] b = new byte[npos * 2];// 记录的总长度，4字节是整数长度
						String logPath = "E:\\Java\\database\\"+u1.getUseDB()+"\\logs";
						FileMgr fLog = new FileMgr(logPath+"\\"+u1.getLogFileName(), 256);
						// 字节数组b,是内存页的实际存储空间
						Page p = new Page(b); // 固定缓冲区大小
						Block blk = fLog.append("\\logs"+"\\"+u1.getLogFileName());  //添加块，即往后追加内容
						p.setString(0, u1.getLogs());// 把该条记录的字符串按位置startpos写入内存页
						fLog.write(blk, p);
						try {
							fLog.getF().close();
						} catch (IOException e1) {
							e1.printStackTrace();
						}
					}
				}
			}
		});
	}
}
