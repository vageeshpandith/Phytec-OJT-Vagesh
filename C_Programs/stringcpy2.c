#include<stdio.h>
void display_string2()
{
	char a[]="Cprogramming";
	int i,j,x,len=0;
	for(i=0;a[i];i++)
	
	{
		len++;
	}

	for(i=0,j=0;i=(len)/2;i++,j--)
	{
             x=a[j];
	     a[i]=a[j];
	     a[j]=x;
	}
}
int main()
{
	display_string2();
}

