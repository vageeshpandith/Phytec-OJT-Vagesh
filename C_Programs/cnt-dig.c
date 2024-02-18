#include<stdio.h>
int fun(int n)
{
	static int cnt;
	if ( n != 0)
	{
	cnt++;
	fun(n/10);
	}
	return cnt;
}
int main()
{
	int n=309;
	printf("%d",fun(n));
	return 0;
}
