#include<stdio.h>
int fun(int n)
{
	if ( n > 100 )
	{
	//printf("%d\n",n);
	return n-10;
	}
	else
	{
	return fun(fun(n+11));
	//printf("%d\n",n);
	}
}
int main()
{
	int n=92;
	printf("%d",fun(n));
	return 0;
}
