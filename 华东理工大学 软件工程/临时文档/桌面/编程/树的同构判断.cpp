#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#define MaxTree 100 //Ԫ�ص�������
#define ElementType char
#define Tree int
//���ܶ���ΪNULL����ΪNULLΪ0����0Ҳ��һ�������±�
 //�ṹ�����ʾ����������̬����

 struct TreeNode
 {
     ElementType Element;
     Tree left;
     Tree right;//���Һ��ӵ������±�
 }T1[MaxTree],T2[MaxTree];
 Tree gen(struct TreeNode T[])
 {
     int i,sum;
     char cl,cr;
     int Root= -1 ;
     int flag[100]={0};
     scanf("%d\n",&sum);//�����￪ʼ���Ƹ�ʽ
     if(sum)
   {
     for(i=0;i<sum;i++)
     {
         scanf("%c %c %c\n",&T[i].Element,&cl,&cr);//�����ַ������ʽ
         if(cl!='-')
         {
             cl=cl-'0';
             T[i].left=cl;
             flag[T[i].left]=1;
             //flag[cl]=1;
         }
         else
            T[i].left= -1 ;
         
         if(cr!='-')
         {
             cr=cr-'0';
             T[i].right=cr;
             flag[T[i].right]=1;
             //flag[cl]=1;
         }
         else
           T[i].right= -1;     
     }
     for(i=0;i<sum;i++)
     {
         if(flag[i]==0)
         break;
     }
       Root=i;
   }
       return Root; 
 }
Tree Is_the_same(Tree R1,Tree R2)
{
    if((R1== -1 )&&(R2== -1 ))//���ſ�����
      return 1;
    else if(((R1== -1 )&&(R2!= -1 ))||((R1!= -1 )&&(R2== -1 )))//��������һ���ǿյ�
      return 0;
    else if(T1[R1].Element!=T2[R2].Element)//�������ĸ�����ֵ��һ��
      return 0;
    else if((T1[R1].left== -1 )&&(T2[R2].left== -1 ))//���������ǿյģ������ж��������Ƿ�Ϊ��
      return Is_the_same(T1[R1].right,T2[R2].right);
   // else if((T1[R1].right==Null)&&(T2[R2].right==Null))
   //   return Is_the_same(T1[R1].left,T2[R2].left);
    else if((T1[R1].left!= -1 )&& (T2[R2].left!= -1 ));
    {
        if(T1[T1[R1].left].Element==T2[T2[R2].left].Element)
         return (Is_the_same(T1[R1].right,T2[R2].right)&&Is_the_same(T1[R1].right,T2[R2].right));
        else
          return (Is_the_same(T1[R1].right,T2[R2].left)&&Is_the_same(T1[R1].left,T2[R2].right));
         
    }

}
int main()
{
    Tree R1,R2;
    int tag=0;
    R1=gen(T1);
    R2=gen(T2);
    tag=Is_the_same(R1,R2);

    if(tag)
     printf("True");
    else
     printf("False");
    


    return 0;
}


