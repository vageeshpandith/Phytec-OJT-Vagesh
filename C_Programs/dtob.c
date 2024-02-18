#include <stdio.h>

void dec2binary(int n) 
{
    if (n > 1) 
    {
        dec2binary(n / 2);
    }
    printf("%d", n % 2);
}

int main() 
{
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary equivalent: ");
    dec2binary(decimal);
    printf("\n");
    return 0;
}

