#include <stdio.h>
#include "SuperStar.h"
#include "malloc.h"
int main(int argc, char *argv[])
{
	 struct SuperStar *star=NULL;
	 star=(struct SuperStar *)malloc(sizeof(struct SuperStar ));
	 setAge(star,60);
	 setName(star,"����");
	 printf("%s  %d��\n", getName(star), getAge(star));
	 printf("%s  %d��\n",star->name,star->age);//��ͨ��struct��field�����ʵ��ֵ
	 
	 free(star);
	return 0;
}
