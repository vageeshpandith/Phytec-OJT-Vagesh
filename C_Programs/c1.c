#include <stdio.h>
int add(int a,int b) 
{
    if (b == 0) 
    {
        return a;
    }
    return add(a + 1, b - 1);
}

int main() 
{
    int x,y,sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    sum = add(x, y);

    printf("Sum: %d\n", sum);

    return 0;
}

