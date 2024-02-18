#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number:\n");
	scanf("%d",&n);
	if (n != 0 && ((n)&(n-1)) == 0)
	{
		printf("Square:\n");
		}
		else
		{
		printf("Not Square:\n");
		}
	}
