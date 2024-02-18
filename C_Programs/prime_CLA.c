#include <stdio.h>

int main(int argc , int *argv[]) 
{
    int count = 0;
    int i,num = 2;
    int pth,qth;
    int is_prime=1;
    if (argc >=4){
    printf("Enter valid no of args\n");
    }

    while (count < 200) 
    {
        for (i=2;i*i<=num;i++) 
        {
            if (num % i == 0) 
            {
                is_prime = 0; 
                break;
            }
        }

        if (is_prime) 
        {
            count++;
            if (count == atoi(argv[1])) 
            {
                pth = num;
            }
            if (count == atoi(argv[2])) 
            {
                qth = num;
            }
        }

        num++;
    }

    printf("The pth prime number is: %d\n", pth);
    printf("The qth prime number is: %d\n", qth);

    return 0;
}
