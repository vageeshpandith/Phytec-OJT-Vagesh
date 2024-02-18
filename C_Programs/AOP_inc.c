#include<stdio.h>
#include<stdlib.h>

int AOP(int *ptr,int n)
{
	int i,sum;
	*ptr=(int *)malloc(n*sizeof(n));
	printf("The Array is :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(*ptr+i));
	}
	for(i=0;i<n;i++)
	{
		sum*=(*ptr+i);
	}
	if (*ptr & sum == 0)
	{
		printf("The array has zeros:\n");
	}
	if(*ptr == NULL)
	{
		printf("Heap is empty:\n");
		//break();
	}
}
int main()
{
	int a[5]={1,2,3,4,5};
	int AOP(a);
	return 0;
} 
