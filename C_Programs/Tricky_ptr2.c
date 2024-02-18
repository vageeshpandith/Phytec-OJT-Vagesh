#include<stdio.h>
int retu(int *ptr,int size)
{
	int x=0;
	for(int i=size;i>0;i--)
	{	
		if((*ptr-i) < size)
		{
			x=*ptr--|*ptr++;
		}
	}
	printf("The pointer address is:%p\n",ptr);
	printf("The value of the ptr is:%d\n",x);
}
int main()
{
	int a[5]={1,2,33,4,55};
	//int *p=x;
	retu(a,5);
	return 0;
}
		
