#include<stdio.h> 
int main(){
    int n = 0,temp;
    int arr[5000] = { 0 };
    //��������
    scanf("%d",&n);
    int i = 0;
    for (i = 0; i < n;i ++){
        scanf("%d",&arr[i]);
    }
    //ȥ��
    for (i = 0; i < n;i++){
        int j = 0;
        for (j = i + 1; j < n;j++){
             //�����ȣ���Ѻ���������ǰ�ƶ�
            if (arr[i] == arr[j])
			{
                int k = 0;
                for (k = j; k < n - 1;k ++)
				{
                    arr[k] = arr[k + 1];
                }
                n--;//���и���Ҳ�𽥼�С 
                j--;
            }
        }
    }
    	for(i=0;i<n/2;i++)   //���Գ�Ԫ�ؽ��� 
	{
		temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
		//�����Ľ��������ķ��� 
	}
	for (i=0;i<n;i++)
	  printf ("%d ",arr[i]);  //���µ�˳�����
	  printf ("\n") ;
	  return 0;

}


