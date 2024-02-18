#include<stdio.h>
int main()
{
	int i,j,n,ld=0,cnt=1;
	int a[]={3,6,8,8,10,12,15,15,15,20};
	n=sizeof(a)/sizeof(int);
	for (i=0;i<n;i++)
	{
		{
			if( a[i] == a[i+1])
			{
				j=i+1;
			}
		   	while ( a[j] == a[i] )
			{
				j++;
				printf("%d %d\n ",a[i],j-i);
				i=j-1;
			}
		}
	}
		for(i=0;i<n;i++)
		{
			if (a[i] == a[i+1] && a[i] != ld)
			{
				printf("%d\n",a[i]);
				ld=a[i];
			}
		}
}


