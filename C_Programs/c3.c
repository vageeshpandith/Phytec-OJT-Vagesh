#include <stdio.h>
#include <ctype.h>

void alpha(const char *a, char *op)
{
    int j = 0;

    for (int i = 0; a[i]!='\0';i++) 
    {
        if (isalpha(a[i])) 
        {
            op[j]=a[i];
            j++;
        }
    }

    op[j] = '\0'; 
}

int main() 
{
    const char *a = "abcde345g?";
    char op[100]; 

    alpha(a, op);

    printf("Alphabets from the input: %s\n", op);

    return 0;
}
