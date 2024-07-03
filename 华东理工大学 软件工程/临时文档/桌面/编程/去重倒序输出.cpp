#include<stdio.h> 
int main(){
    int n = 0,temp;
    int arr[5000] = { 0 };
    //输入数据
    scanf("%d",&n);
    int i = 0;
    for (i = 0; i < n;i ++){
        scanf("%d",&arr[i]);
    }
    //去重
    for (i = 0; i < n;i++){
        int j = 0;
        for (j = i + 1; j < n;j++){
             //如果相等，则把后续数字向前移动
            if (arr[i] == arr[j])
			{
                int k = 0;
                for (k = j; k < n - 1;k ++)
				{
                    arr[k] = arr[k + 1];
                }
                n--;//数列个数也逐渐减小 
                j--;
            }
        }
    }
    	for(i=0;i<n/2;i++)   //将对称元素交换 
	{
		temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
		//常见的交换变量的方法 
	}
	for (i=0;i<n;i++)
	  printf ("%d ",arr[i]);  //按新的顺序输出
	  printf ("\n") ;
	  return 0;

}


