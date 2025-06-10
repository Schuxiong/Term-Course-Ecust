package view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Insets;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import java.awt.*;


import utils.User;

public class Login extends JFrame {
	private static final long serialVersionUID = 1L;
	// 背景
	BufferedImage LoginImg;
	BufferedImage registerImg;
	BufferedImage iconImg;

	JPanel pan = new JPanel(null); // 空布局（绝对定位布局） 改用自己写面板

	// 标签
	JLabel title = new JLabel("Welcome to DBMS-lite");
	JLabel username = new JLabel(" ");
	JLabel password = new JLabel(" ");
	// 文本框与密码框
	JTextField usernameText = new JTextField();
	JPasswordField passwordText = new JPasswordField();
	// 字体
	Font font1 = new Font("Yahei", Font.BOLD, 30);
	Font font2 = new Font("Yahei", Font.BOLD, 20);
	Font font3 = new Font("Yahei", Font.BOLD, 20);
	Font fontx = new Font("Yahei", Font.BOLD, 40);
	// 两个按钮
	JButton enter = new JButton();
	JButton register = new JButton();

	// 初始化
	public void init() {
		try { // 注意文件路径
			iconImg = ImageIO.read(new File("img/icon1.png"));
			LoginImg = ImageIO.read(new File("img/4.png"));
			registerImg = ImageIO.read(new File("img/3.png"));

		} catch (IOException e) {
			e.printStackTrace();
		}

		this.setSize(600, 500);// 面板大小
		this.setContentPane(new BackgroundPanel()); // 设置背景
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.setLocationRelativeTo(null);// 屏幕居中
		pan.setOpaque(false);

		this.addPart();
		this.addLis();
		this.setTitle("欢迎进入DBMS-lite，请先登录");
		this.setIconImage(iconImg);
		this.pack();
		this.setVisible(true);  //设为可见


	}
	// 绘制带有阴影的文本
	private void drawShadowedText(Graphics g, String text, int x, int y, Font font, Color textColor, Color shadowColor) {
		Graphics2D g2d = (Graphics2D) g;
		FontMetrics fm = g2d.getFontMetrics(font);
		int textWidth = fm.stringWidth(text);
		g2d.setFont(font);

		// 绘制阴影文本
		g2d.setColor(shadowColor);
		g2d.drawString(text, x + 2, y + 2);

		// 绘制主要文本
		g2d.setColor(textColor);
		g2d.drawString(text, x, y);
	}
	private class BackgroundPanel extends JPanel {
		private BufferedImage backgroundImg;

		public BackgroundPanel() {
			try {
				backgroundImg = ImageIO.read(new File("img/background.png")); // 背景图像的文件路径
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		@Override
		protected void paintComponent(Graphics g) {
			super.paintComponent(g);
			if (backgroundImg != null) {
				g.drawImage(backgroundImg, 0, 0, getWidth(), getHeight(), this);

				// 在背景上绘制带阴影的文本
				g.setFont(fontx);
				drawShadowedText(g, "Welcome to DBMS-lite", 90, 90, fontx, Color.WHITE, Color.BLACK);
				Font labelFont = username.getFont();
				drawShadowedText(g, "User：", 70, 200, labelFont, Color.WHITE, Color.BLACK);
				Font labelFont1 = password.getFont();
				drawShadowedText(g, "Pword：", 70, 295, labelFont, Color.WHITE, Color.BLACK);

			}
		}
	}


	// 添加组件
	public void addPart() {
		pan.setPreferredSize(new Dimension(600, 500));

		/*// 登录
		pan.add(title);// 添加
		title.setBounds(80, 60, 450, 45);
		title.setFont(fontx);// 设置字体
//		title.setForeground(Color.DARK_GRAY);//深灰色 */
// 设置标签为透明

		// 第一行:标签+文本框
		pan.add(username);
		username.setBounds(70, 160, 110, 55);
		username.setFont(font2);
		username.setOpaque(false);



		pan.add(usernameText);
		usernameText.setBounds(150, 160, 320, 45);
		usernameText.setFont(font3);
		usernameText.setOpaque(false);

		// 第二行 ：标签+密码框
		pan.add(password);
		password.setBounds(70, 265, 110, 45);
		password.setFont(font2);
		password.setForeground( Color.WHITE);

		pan.add(passwordText);
		passwordText.setBounds(150, 265, 320, 45);
		passwordText.setFont(font1);
		passwordText.setEchoChar('*');
		passwordText.setOpaque(false);

		// 两个按钮
		pan.add(enter);
		//enter.setBounds(50, 350, 180, 100);
		enter.setBounds(90, 350, 127, 127);
		enter.setIcon(new ImageIcon(LoginImg));
		enter.setMargin(new Insets(0, 0, 0, 0));// 设置边距
		enter.setBorderPainted(false);// 不绘制边框
		enter.setContentAreaFilled(false);// 除去默认的背景填充

		pan.add(register);
		//register.setBounds(370, 350, 180, 100);
		register.setBounds(380, 350, 127, 127);
		register.setIcon(new ImageIcon(registerImg));
		register.setMargin(new Insets(0, 0, 0, 0));// 设置边距
		register.setBorderPainted(false);// 不绘制边框
		register.setContentAreaFilled(false);// 除去默认的背景填充
		this.add(pan);
	}

	// 添加事件监听
	public void addLis() {
		// 匿名内部类 （匿名接口实现类） e-> Lambda表达式
		// 匿名内部类写外部这个类的当前对象，需要带上外部类的类名，再写this
		enter.addActionListener(e -> {
			String user = usernameText.getText();
			String psw = new String(passwordText.getPassword());

			BufferedReader br = null;
			String thisLine;
			String[] oneUser;
			boolean flag = false;
			User u1 = new User();
			try {
				br = new BufferedReader(new FileReader("./config/user"));
				while ((thisLine = br.readLine()) != null) {
					oneUser = thisLine.split("-");
					if (oneUser[0].equals(user) && oneUser[1].equals(psw)) {
						flag = true;
						u1.setUser(user);
						u1.setPassword(psw);
						u1.setLevel(Integer.valueOf(oneUser[2]));
						u1 = getPermission(u1, oneUser[3]);
						if ("1".equals(oneUser[2])) {
							JOptionPane.showMessageDialog(pan, "管理员: " + user + " 登录成功\n即将跳转...");
						} else {
							JOptionPane.showMessageDialog(pan, "用户: " + user + " 登录成功\n即将跳转...");
						}
						Login.this.setVisible(false);// 窗口隐藏（并没有关闭!）
						new MainView(u1);
					}
				}
				if (!flag) {
					JOptionPane.showMessageDialog(pan, "用户名或密码错误");
					usernameText.setText("");
					passwordText.setText("");
				}
			} catch (FileNotFoundException e1) {
				e1.printStackTrace();
			} catch (IOException e2) {
				e2.printStackTrace();
			}

		});
		register.addActionListener(e -> {
			String user = usernameText.getText();
			String psw = new String(passwordText.getPassword());// password是char型数组
			// 注冊：输入 用户名和密码 到数据库 查该用户名的所有信息 得到对象
			if (user != null || psw != null) {
				JOptionPane.showMessageDialog(pan, "暂时不支持注册功能！");
			}

		});
		usernameText.addKeyListener(new KeyAdapter() {
			@Override
			public void keyReleased(KeyEvent e) {
				int keycode = e.getKeyCode();
				if (keycode == KeyEvent.VK_ENTER) {
					passwordText.requestFocus();
				}
			}
		});
	}
	
	private User  getPermission(User u1,String permission) {
		String[] split = permission.split(",");
		for (String string : split) {
			if("Select".equals(string)) {
				u1.setSelect(true);
			}else if("Create".equals(string)) {
				u1.setCreate(true);
			}else if("Insert".equals(string)) {
				u1.setInsert(true);;
			}else if("Update".equals(string)) {
				u1.setUpdate(true);
			}else if("Delete".equals(string)) {
				u1.setDelete(true);
			}
		}
		return u1;
	}
}
