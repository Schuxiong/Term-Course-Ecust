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
	
	//����
	for(int j=0;j<total;j++){
		scanf("%c %c %c",&t[j].val,&rc,&lc);
		ch= getchar();
		
		//������ҽ�� 
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


//�ж�

int judgment(int root1,int root2){
	
	//��Ϊ��
	if(root1==-1&&root2==-1){
		return 1;
	} 
	
	//һ��һ����
	if(root1==-1&&root2!=-1||root1!=-1&&root2==-1){
		return 0;
	} 
	
	//���ڵ㲻ͬ 
	if(root1!=root2){
		return 0;
	}
	//���������� 
	if(t1[root1].left==-1&&t2[root2].left==-1){
		return judgment(t1[root1].right,t2[root2].right);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	//����������Ϊ��
	if(t1[root1].left!=-1&&t2[root2].left!=-1) {
		//�����������
		if(t1[t1[root1].left].val==t2[t2[root2].left].val){
			//�ݹ��ж�����������
			return (judgment(t1[root1].left,t2[root2].left)
					&&
					judgment(t1[root1].right,t2[root2].right)) ; 
		} 
		//����ӵ����Ҷ��� 
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

