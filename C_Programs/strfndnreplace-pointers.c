#include<stdio.h>
void findandreplace(char *pch,char findvar,char replacevar)
{
	for (int i=0;*(pch+i);i++)
	{
		if (*(pch+i)==findvar)
		{
			*(pch+i)=replacevar;
		}
	}
}





int main()
{
	char a[20]="Emin is captivating";
	char *ptr;
	ptr=a;
	findandreplace(ptr,'i','f');
	printf("After replacing the character::\n");
	printf("%s\n",a);
}

