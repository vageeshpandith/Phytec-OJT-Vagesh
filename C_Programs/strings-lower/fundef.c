#include<stdio.h>
void str_lower()
{
	char b[]="EMINRIyaZ";
	int i=0;
	for(i=0;b[i];i++)
	{
		b[i]=b[i]+32;
	}
	printf("the lower case is = %s\n",b);
}

