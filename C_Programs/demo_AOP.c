#include<stdio.h>
int main()
{
	int b[5]={1,2,3,4,5};
	int *ptr=b;
	for (int i=0;i<5;i++)
	{
		printf("%d\n",(*ptr+i));
	}
}
