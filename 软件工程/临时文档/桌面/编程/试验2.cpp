#include<stdio.h>
struct tree{
	char val;
	int left;
	int right;
}t1[100],t2[100];

int creat(struct tree t[]){
	int total,root;
	char ch , rc , lc;
	scanf("%d",&total);
	ch=getchar();
	int check[total];
	for(int i=0;i<total;i++){
		check[i]=0;
	}
	
	//输入
	for(int j=0;j<total;j++){
		scanf("%c %c %c",&t[j].val,&rc,&lc);
		ch= getchar();
		
		//填充左右结点 
		if (rc!='-1') {
			t[j].right=rc-'0';
			check[t[j].right]=1;
		} 	
		else {
			t[j].right=-1;
		}
		
		if(lc!='-1'){
			t[j].left=lc-'0';
			check[t[j].left]=1;
		}
		else{
			t[j].left=-1;
		}
		
	} 

	for(int i=0;i<total;i++){
		if(check[i]==0){
			root=i;
			break;
		}
	} 
	return root;
}


//判断

int judgment(int root1,int root2){
	
	//都为空
	if(root1==-1&&root2==-1){
		return 1;
	} 
	
	//一空一不空
	if(root1==-1&&root2!=-1||root1!=-1&&root2==-1){
		return 0;
	} 
	
	//根节点不同 
	if(root1!=root2){
		return 0;
	}
	//左子树都空 
	if(t1[root1].left==-1&&t2[root2].left==-1){
		return judgment(t1[root1].right,t2[root2].right);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	//左子树都不为空
	if(t1[root1].left!=-1&&t2[root2].left!=-1) {
		//如果左儿子相等
		if(t1[t1[root1].left].val==t2[t2[root2].left].val){
			//递归判断左树和右树
			return (judgment(t1[root1].left,t2[root2].left)
					&&
					judgment(t1[root1].right,t2[root2].right)) ; 
		} 
		//左儿子等于右儿子 
		else{
			return (judgment(t1[root1].left,t2[root2].right)
					&&
					judgment(t1[root1].right,t2[root2].left)) ; 
		}
	}
	
} 
int main(){
	int root1 =creat(t1);
	int root2 =creat(t2);
	
	int result=judgment(root1,root2);
	if(result==1){
		printf("True\n");
	}
	else{
		printf("False\n"); 
	}
	return 0;
}

