#include <stdio.h>
int main()
{
  int n,i,j,k;
  printf("Enter the number of prime numbers to print\n");
  scanf("%d", &n);
  
  printf("The prime numbers for %d are:\n",n);
  for (i=2;i<=n;i++)
  {
    for (j=2;j<=i;j++)
    {
      if (i%j == 0)
        break;
    }
    if (i == j)
    {
      printf("%d ", i);
    }
    }
    printf("\n");
	return 0;
}
