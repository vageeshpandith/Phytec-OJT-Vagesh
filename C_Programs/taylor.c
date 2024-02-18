#include<stdio.h>
int main()
{
	int x,n=4,i;
	static int s=1;
	//if (n==0)
	//	return 1;
	for ( i=n-1;i<=0;i--)
	{
		s=((1+x/i)*s);
		s++;
	}
	printf("%d\n",s);
}
	
