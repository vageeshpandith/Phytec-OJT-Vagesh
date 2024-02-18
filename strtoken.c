#include<stdio.h>
#include<string.h>
int main()
{
	char b[50][100]={"Rahul:dravid:9090909090:rahul@gmail.com","Sachin:Tendulkar:9898989898:sachin@gmail.com"};
	char *token1;
	
	for(int i=0;i<2;i++)
	{
		token1=strtok(b[i],":");
		while (token1!=NULL)

		{
			printf("Token=%s\n",token1);
			token1=strtok(NULL,":");
		}
	}
}	
