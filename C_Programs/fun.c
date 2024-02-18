#include<stdio.h>
int count (int n)
{
	static int d=1;
	printf("%d\n",n);
	printf("%d\n",d);
	d++;
	if ( n>1 )
	count(n-1);
	printf("%d\n",d);
}
int main()
{
	int n=3;
	count(n);
	return 0;
}
	
