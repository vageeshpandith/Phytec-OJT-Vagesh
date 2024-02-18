#include<stdio.h>
int main()
{
	int i,n;
	printf("Enter the numbers:");
	scanf("%d",&n);
	
	printf("Even numbers are:\n");
	for(i=0;i<n;i=i+2)
	{
	    printf("%d ",i);
	}
	printf("\n");
	
	printf("Odd numbers are:\n");
	for(i=1;i<n;i=i+2)
	{
	    printf("%d ",i);
	}
	printf("\n");
}
	
	
