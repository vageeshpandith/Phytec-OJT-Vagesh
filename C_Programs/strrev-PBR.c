#include<stdio.h>
void mystrrev(char *ptch)
{
	int i,j,len;
	char x;
	for (i=0;*(ptch+i);i++)
	{
		len++;
	}
	for (i=0,j=len-1;i<=(len/2);i++,j--)
	{
		x=*(ptch+i);
		*(ptch+i)=*(ptch+j);
		*(ptch+j)=x;
	}
	
}	
int main()
{
	char a[40]="Emin is popular";
	char *pch;
	pch=a;
	mystrrev(pch);
	printf("The reversed string is ::%s\n",a);
}
