#include<stdio.h>
void display_demo()
{
	unsigned int num1;
	unsigned int bitmask;
	unsigned int res;
	printf("enter the number\n");
	scanf("%u",&num1);
	int i=31;
	while(i>=0)
	{
		bitmask=1<<i;
		res=num1&bitmask;
		if(res == 0)
		printf("0");
	else 
		printf("1");
		i--;
	}
	printf("\n");
}
int main()
{
	display_demo();
}

