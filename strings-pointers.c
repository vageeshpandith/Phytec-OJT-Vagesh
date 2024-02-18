#include<stdio.h>
int main()
{
	char a[20]="Hello Bengaluru";
	char b[20];
	int i;
	char *p1,*p2;
	p1=a;
	p2=b;
	for (i=0;*(p1+i);i++)
	{
		*(p2+i)=*(p1+i);
	}
	printf("The copied string is:: %s\n",a);
	printf("The actual string is ::%s\n",b);

}
