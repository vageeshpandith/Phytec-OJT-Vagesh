#include<stdio.h>
void sum_arrays()
{
	int i,j,n,m;
       	printf("Enter the rows and columns of an array\n");
        scanf("%d%d",&n,&m);
        int a[n][m],b[n][m],sum[n][m];
        printf("Enter the array elements of 1st matrix::\n");
	for (i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the array elements of 2nd array\n");
	for (i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sum[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("The sum of the matrixes is ::\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\n",sum[i][j]);
		}
	}	
}
