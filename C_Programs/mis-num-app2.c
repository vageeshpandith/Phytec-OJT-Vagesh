
#include <stdio.h>
int printarray(int a[], int n)
{
    int i,sum=0;
    sum = (n+1)*(n+2)/2;
    for (i=0; i<n; i++)
        sum=sum-a[i];
    return sum;
}
void main()
{
    int a[] = { 1,2,3,4,5,6,7,8,9,11,12 };
    int N = sizeof(a) / sizeof(int);
    int m = printarray(a, N);
    printf("%d\n", m);
}
		
	
	
