#include "onMidPointEllispe.h"
/**************************************************
* 已知椭圆的长短轴a,b 
* 根据椭圆的中点Bresenham算法，扫描转换椭圆
* 以glBegin(GL_POINTS);glEnd();方式，绘制椭圆
***************************************************/
void  onMidPointEllispe(int a,int b){
	int x,y;
    float d1,d2;
	glBegin(GL_POINTS);
		x=0;y=b;
		d1=b*b+a*a*(-b+0.25);
		glVertex2i(x,y);
		glVertex2i(-x,-y);
		glVertex2i(-x,y);
		glVertex2i(x,-y);
		while(b*b*(x+1)<a*a*(y-0.5))
		{ 
			if(d1<=0){
				d1+=b*b*(2*x+3);
				x++;
			}
			else{
				d1+=b*b*(2*x+3)+a*a*(-2*y+2);
				x++; y--; 
			}
			glVertex2f(x,y);
			glVertex2f(-x,-y);
			glVertex2f(-x,y);
			glVertex2f(x,-y);
		}/*while上半部分*/
		d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
		while(y>0) 
		{
			if(d2<=0){
        		d2+=b*b*(2*x+2)+a*a*(-2*y+3);
				x++; y--;
			}
			else{	
				d2+=a*a*(-2*y+3);
				y--; 
			}
			glVertex2f(x,y);
			glVertex2f(-x,-y);
			glVertex2f(-x,y);
			glVertex2f(x,-y);
		}	
	glEnd();
}