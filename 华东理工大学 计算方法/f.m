function y=f(x)
a=input('输入积分下限a=');
b=input('输入积分上限b=');
eps=input('输入误差限eps=');
x=[a,b];
y=f(x);
h=b-a;
T1=h/2*(f(a)+f(b));           %没有进行二等分时梯形面积
while 1                       %表示一直循环下去，直到判断条件成立，跳出循环
      u=h/2;                  %对区间进行二等分
      H=0;                    %给H设定初值0
      x=a+u;                  %x进行二等分后从a以相应的步长u向右移动直到b 
      while x<b               %该内循环用以计算二分后节点对应的函数值，见（2）
      H=H+f(x);
      x=x+h;                  %此处令x=x+h是为了让x从a以相应的步长u向右移动直到b后跳出循环
      end
       T2=1/2*(T1+h*H),       %（2）
        if abs(T2-T1)<eps     %判断
        I=T2+(T2-T1)/3;       %数学上的近似计算式
        disp(I),              %表示显示I的值
        break;                %跳出循环
        end
     h=u,T1=T2                %此处令h=u，是为了上面的u=h,也就是再次二分区间，此时将T2的值赋给T1，以此迭代
end
if x==0
   y=1,
else
   y=sin(x)/x,
end