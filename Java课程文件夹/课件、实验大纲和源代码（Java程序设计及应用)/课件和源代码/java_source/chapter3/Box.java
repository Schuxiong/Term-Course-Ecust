public class Box
{
	int length,width,height; //成员变量

	void setLength(int lengthValue)	{ length=lengthValue;}
	int getLength() {return length;}

	void setWidth(int widthValue){width=widthValue;}
	int getWidth(){return width;}

	void setHeight(int heightValue){height=heightValue;}
	int getHeight(){return height;}

	void setBox(int lengthValue,int widthValue ,int HeightValue)
	{
		length=lengthValue;
		width=widthValue;
		height=heightValue
	}//成员方法
}