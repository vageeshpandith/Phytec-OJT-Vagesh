#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	printf("Enter the size:\n");
	scanf("%d",&n);
	
	int *a = (int *)malloc(n*sizeof(int));
	if(a==NULL)
	{	
		printf("The memory not allocated:\n");
	}
	printf("The array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	int sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	printf("Sum of array is:%d\n",sum);
	free(a);
}
