#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num = 8;

    if (num & 8) 
    {
        printf("MSB 1\n");
    } 
    else 
    {
        printf("MSB 0\n");
    }

    return 0;
}

