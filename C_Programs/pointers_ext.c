#include<stdio.h>
void *ptr(int *a , int *p)
{
	while(1)
	{
	a=5;
	*p=a;
	}
	printf("The values of pointer : %d",*ptr);
	printf("Address of this pointer : %p",ptr);
}
void main()
{
	void *ptr(5 , 6);
	
}
