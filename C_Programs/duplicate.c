#include<stdio.h>
int main()
{
	int i,n,ld=0;
	int a[10]={3,6,8,8,10,12,15,15,15,20};
	n=sizeof(a)/sizeof(int);
	for(i=0;i<n;i++)
	{
		if (a[i] == a[i+1] && a[i]!=ld)
		{
			printf("%d\n",a[i]);
			ld=a[i];
		}
	}
}
