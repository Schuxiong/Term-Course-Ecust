#include <stdio.h>  
#define MaxTree 10  
#define Null -1  
    
typedef int Tree ;  
typedef char  ElementType ;  
 
struct TreeNode  
{  
    ElementType Element ;  
    Tree Left ;  
    Tree Right ;  
} Tree1[MaxTree],Tree2[MaxTree];  
  
Tree BuildeTree(struct TreeNode T[])  
{  
    int i,N,check[MaxTree];  
    int cl,cr;  
    int Root;  
    scanf("%d",&N);  
  
    if(N!=0)  
    {  
        for( i=0;i<N;i++) check[i] = 0 ;  
        for( i=0;i<N;i++)  
        {  
            scanf(" %c %d %d",&T[i].Element,&cl,&cr) ;
  
            if(cl!=-1)  
            {  
                T[i].Left=cl;  
                check[T[i].Left]=1 ;  
            }  
            else T[i].Left=Null ;  
  
            if(cr!=-1)  
             {  
                 T[i].Right =cr;  
                 check[T[i].Right]=1 ;  
             }  
            else T[i].Right=Null ;  
        }  
    }  
    else  
        return  Null ;  
  
    for(i=0;i<N;i++ )  
    {  
        if(check[i]==0 )  
        break ;  
    }  
    Root=i ;  
  
    return  Root ;  
}  
int Isomorphic(Tree R1,Tree R2)
{
	 //左右孩子都为空  同构 
	 if((R1==Null)&&(R2==Null))
	     return 1;
     //左右不同空  非同构 
	 if(((R1==Null)&&(R2!=Null))||((R2==Null)&&(R1!=Null)))
	    return 0;  
	//结点不同 非同构 
	 if(Tree1[R1].Element!=Tree2[R2].Element)
	     return 0; 
    //函数递归 
	 else
	 {
	     if(Isomorphic(Tree1[R1].Left,Tree2[R2].Left)&&Isomorphic(Tree1[R1].Right,Tree2[R2].Right)) 
		    return 1;
	    else if(Isomorphic(Tree1[R1].Left,Tree2[R2].Right)&&Isomorphic(Tree1[R1].Right,Tree2[R2].Left))
		    return 1;
		 else
		    return 0;
    }	   			 	 
}  
   
int main(  )  
{  
    Tree Root1 , Root2 ;  
    Root1 = BuildeTree( Tree1 ) ;  
    Root2 = BuildeTree( Tree2 ) ;  
  
  
    if( Isomorphic( Root1,Root2 ) )  
        printf("True\n") ;  
    else  
        printf("False\n") ;  
  
    return 0 ;  
  
}  
