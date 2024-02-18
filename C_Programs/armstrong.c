#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
 {
    int n, sum = 0, temp, rem, count = 0;
    printf("Enter the number:\n");
    scanf("%d", &n);
    temp = n;

    while (temp != 0) 
    {
        temp = temp / 10;
        count++;
    }

    temp = n;

    while (temp != 0) 
    {
        rem = temp % 10;
        sum = sum + pow(rem, count);
        temp = temp / 10;
    }

    if (sum == n)
    {
        printf("%d is an Armstrong number.\n", n);
    } else {
        printf("%d is not an Armstrong number.\n", n);
    }

    return 0;
}

