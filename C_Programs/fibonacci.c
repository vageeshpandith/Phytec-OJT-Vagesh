#include<stdio.h>
int main()
{
	int t0=0,t1=1,s,n=10;
	printf("%d %d ",t0,t1);
	for (int i=2;i<n;i++)
	{
		s=t0+t1;
		printf("%d ",s);
		t0=t1;
		t1=s;
	}
	return 0;
}
