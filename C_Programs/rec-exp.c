#include<stdio.h>
int expp(int n,int m)
{
	if ( n == 0 )
	{
		return 1;
	}
	else
	{
		return expp(n-1,m)*m;
	}
}
int main()
{
	int n=5,m=2;
	printf("%d\n ",expp(n,m));
	return 0;
}
