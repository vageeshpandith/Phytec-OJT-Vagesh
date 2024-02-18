#include <stdio.h>

int main()
{
    char a = 'a';
    switch(a)
    {
        case "a": printf("a");
        case "b": printf("b");
        case "c": printf("c");
        default:  printf("default");
    }

    return 0;
}
