#include<stdio.h>
int retu(int *ptr,int n)
{
	int *i=ptr;
	int *j=ptr+n-1;
	while(i<j)
	{
		int temp=*i;
		*i=*j;
		*j=temp;
		i++;
		j--;
	}
}
int main()
{
	int a[5]={1,2,3,4,5};
	int i,n=sizeof(a)/sizeof(int);
	printf("Original Array \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	retu(a,n);
	printf("Returned Array \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
