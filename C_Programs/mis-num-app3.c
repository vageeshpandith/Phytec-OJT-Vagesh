
#include <stdio.h>
int printarray(int a[], int n)
{
    int i,sum=1;
 
    for (i=2;i<(n+1);i++)
     {
        sum=sum+i;
        sum=sum-a[i-2];
     }
    return sum;
}
void main()
{
    int a[] = {1,2,4,5};
    int N = sizeof(a) / sizeof(int);
    printf("%d\n",printarray(a, N));
}

		
	
	
