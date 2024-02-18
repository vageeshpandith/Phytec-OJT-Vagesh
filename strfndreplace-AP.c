#include<stdio.h>
void findandreplace(char *pch[10],char findvar,char replacevar)
{
	for (int i=0;*(pch[10]+i);i++)
	{
		if (*(pch[10]+i)==findvar)
		{
			*(pch[10]+i)=replacevar;
		}
	}
}

int main()
{
	char a[20][50]={"Working hard","To fulfill dream"};
	char *ptr[10];
	ptr[0]=a;
	findandreplace(ptr,"hard",'f');
	printf("After replacing the character::\n");
	printf("%s\n",&a[0]);
}

