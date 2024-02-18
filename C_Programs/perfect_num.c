#include<stdio.h>
int main()
{
	int n,i,res=0;
	printf("Enter the number:\n");
	scanf("%d",&n);
	
	for(i=1;i<n;i++)
	{
	  if(n%i == 0)
	  {
	      res=res+i;
	  }
	}
	if(res == n)
	{
		printf("Perfect Number:\n");
		}
		else{ 
		printf("Not Perfect Number:\n");
}
}
