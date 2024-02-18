#include<stdio.h>
int fun(int n)
{
	if ( n > 0 )
	{
	printf("%d\n",n);
	fun(n-1);
	printf("%d\n",n);
	}
}
int main()
{
	int n=3;
	fun(n);
	return 0;
}
