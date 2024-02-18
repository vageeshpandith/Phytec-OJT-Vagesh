#include<stdio.h>
void printbinary(unsigned int num)
{
	unsigned int num;
	unsigned int bitmask;
	printf("enter the number\n");
	scanf("%u",&num);
	printf("enter the bitmask\n");
	scanf("%u",&bitmask);
	printf("before resettin=%u\n",num);
	num=num|bitmask;
	printf("after resetting=%u\n",num);
}
int main()
{
	printbinary(unsigned int num);
}
