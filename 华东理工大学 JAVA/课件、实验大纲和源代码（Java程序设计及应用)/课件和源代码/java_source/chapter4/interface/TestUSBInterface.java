interface USBInterface {
	int version=2 ;     //USB驱动程序版本
	public void work(); //功能
}

class U implements USBInterface{
	public void work(){      System.out.println("U: 存储数据!");	}
}
class KeyboardUSB implements USBInterface{
	public void work(){      System.out.println("KeyboardUSB: 输入数据  !");	}
}

class MouseUSB implements USBInterface{
	public void work(){      System.out.println("MouseUSB: 方便输入数据   !");	}
} 
class DisplayUSB implements USBInterface{
	public void work(){      System.out.println(" DisplayUSB:显示数据  !");	}
}
public class TestUSBInterface{  
	public static void main(String[] args){
      USBInterface usb=null;
      U myU=new U();
      KeyboardUSB mykeyboard=new KeyboardUSB();
      MouseUSB mymouse=new MouseUSB();
      DisplayUSB mydisplay=new DisplayUSB();

	  usb=myU;
	  usb.work();

	  usb=mykeyboard;
	  usb.work();

	  usb=mymouse;
	  usb.work();

	  usb=mydisplay;
	  usb.work(); 

	}
}