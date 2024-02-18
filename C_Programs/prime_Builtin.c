/*Using builtin function printing prime numbers*/

#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) 
{
    if (num <= 1) 
    {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0) 
        {
            return 0; // If divisible by any number, it's not prime
        }
    }
    return 1; // If no divisors found, it's prime
}

int main() {
    printf("Prime numbers from 1 to 20 are:\n");
    for (int i = 1; i <= 20; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}

