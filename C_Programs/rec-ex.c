#include<stdio.h>
int fun(int n)
{
	if ( n > 0 )
	{
	//printf("%d\n",n);
	return fun(n-1)+n;
	//printf("%d\n",n);
	}
	return 0;
}
int main()
{
	int n=5;
	printf("%d",fun(n));
	return 0;
}
