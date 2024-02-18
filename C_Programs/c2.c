#include <stdio.h>

int main() 
{
    int a[100], n, max = 0, maxf;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        if (count > max) {
            max = count;
            maxf = a[i];
        }
    }

    printf("The element with the highest frequency is %d, which appears %d times.\n", maxf, max);

    return 0;
}

