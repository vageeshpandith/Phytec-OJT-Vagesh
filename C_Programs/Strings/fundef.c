#include<stdio.h>
void str_upper()
{
	char b[]="eminriyaz";
	int i=0;
	for(i=0;b[i];i++)
	{
		b[i]=b[i]-32;
	}
	printf("the uppercase is = %s\n",b);
}

