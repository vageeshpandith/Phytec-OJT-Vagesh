#include<stdio.h>
int main()
{
	char a[20]="C programmers";
	char *ptr;
	ptr=a;
	mystrrev(ptr);
	//for (int i=0;*(ptr+i);i++)
	printf("%s",ptr);
	printf("\n");
	return 0;
}
