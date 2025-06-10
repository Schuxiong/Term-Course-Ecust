#include<stdio.h>
#include<math.h>
int main ()
{
float s1, s2,det;
int a,b,c;
scanf("%d %d %d", &a, &b, &c) ;
if (a==0){
   if(b!=0){
    s1=-c*1.0/b;
printf("%.3f\n", s1);
}else{
if (c==0){
printf("INF\n");
}
else{
printf("NO\n");
}
}
}
else{
det=b*b-4*a*c;
if (det<0){
printf("NO\n");
}
else
if (det==0){
s1=(-b+sqrt (b*b-4*a*c))*1.0/(2*a) ;
printf("%.3f\n", s1) ;
}
else if (det>0){
s1=(-b+sqrt (b*b-4*a*c))*1.0/(2*a) ;
s2=(-b-sqrt(b*b-4*a*c))*1.0/(2*a);
if (s2<s1)
printf("%.3f %.3f\n", s2, s1);
else
printf("%.3f %.3f\n", s1,s2);
}
}
return 0;
}
