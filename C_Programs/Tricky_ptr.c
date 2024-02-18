#include<stdio.h>
int val(int *ptr,int n)
{
	float j;
	printf("Enter numbers :\n");
	for(int i=0;i<n;i++)
	{	
		if((*ptr+i) > 0)
		{
			j=*ptr++;		
		}
	}
	printf("The pointer address is:\n%p\n",ptr);
	printf("The value of the ptr is:%f\n",j);
}
int main()
{
	int x[5]={1,2,33,4,55};
	//int *p=x;
	val(x,5);
	return 0;
}
		
