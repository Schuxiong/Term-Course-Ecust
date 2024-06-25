#include <stdio.h>
int main ()
{
	int n,ah,am,as,bh,bm,bs;
	scanf ("%d",&n);
	while (n--)
	{
		scanf("%d%d%d%d%d%d",&ah,&am,&as,&bh,&bm,&bs);
		bs+=as;
		if (bs>60) 
		{
			bm+=bs/60;
			bs=bs%60;
		}
		bm+=am;
		if (bm>60) 
		{
			bh+=bm/60;
			bm=bm%60;
		}
		bh+=ah;
		printf ("%d %d %d\n",bh,bm,bs);
	}
	return 0;
}
