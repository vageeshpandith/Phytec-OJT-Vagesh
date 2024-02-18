#include<stdio.h>
int fun(int n)
{
	static int x=0;
	if ( n > 0 )
	{
	printf("%d\n",n);
	x++;
	printf("%d\n",x);
	return fun(n-1)+x;
	}
	return 0;
}
int main()
{
	int n=5;
	printf("%d",fun(n));
	return 0;
}
