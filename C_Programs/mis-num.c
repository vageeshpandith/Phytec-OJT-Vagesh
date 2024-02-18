#include<stdio.h>
void printarray()
{
	int n,kn=5,sum=0,m;
	//int a[20];
	//printf("Enter the size of an array\n");
	//scanf("%d",&n);
	int a[12]={6,7,8,9,10,11,12,13,14,16,17};
	//k=sizeof(a)/sizeof(int);
	//printf("Enter the array elements:\n");
	//for (int i=0;i<k;i++)
	//{
	//	scanf("%d",a[i]);
	//}
	kn=kn*(kn+1)/2;
	int k=17;
	k=k*(k+1)/2;
	kn=k-kn;
	for(int i=0;i<12;i++)
	{
		sum=sum+a[i];
	}
	m=kn-sum;
	printf("The missing no is: %d\n",m);
}
int main ()
{
	printarray();
}
	
		
	
	
