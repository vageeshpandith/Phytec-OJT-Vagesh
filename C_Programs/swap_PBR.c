/*Swapping two numbers using pass by reference*/

#include<stdio.h>
int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int x=10,y=5;
	printf("Before Swap:\n");
	printf("%d %d \n",x,y);
	printf("After Swap:\n");
	swap(&x,&y);
	printf("%d %d\n",x,y);
	return 0;
}
