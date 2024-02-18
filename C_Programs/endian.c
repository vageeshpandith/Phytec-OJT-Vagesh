#include<stdio.h>
int checkendian();
int main()
{
	int endianness=checkendian();
	if (endianness == 1)
	{
	printf("Little Endian\n");
	}else{
	printf("Big endian\n");
	}
}
int checkendian()
{
	int n;
	printf("Enter a number\n");
	if(scanf("%d",&n) != 1)
	{
		printf("Error\n");
		return -1;
	}
	
	char *ptr=(char *)&n;
	if(*ptr == n&0xFF)
	{
		return 1;
	}else{
	return 0;
	}
}

