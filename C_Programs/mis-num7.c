#include<stdio.h>
void printarray()
{
	int n,sum=0,m;
	printf("Enter the size of an array\n");
	scanf("%d",&n);
	int a[12]={1,2,3,4,5,6,8,9,10,11,12};
	//printf("Enter the array elements:\n");
	//for (int i=0;i<n;i++)
	//{
	//	scanf("%d",&a[i]);
	//}
	int k=sizeof(a)/sizeof(int);
	k=k*(k+1)/2;
	for(int i=0;i<12;i++)
	{
		sum=sum+a[i];
	}
	m=k-sum;
	printf("The missing no is: %d\n",m);
}
int main ()
{
	printarray();
}
	
		
	
	
