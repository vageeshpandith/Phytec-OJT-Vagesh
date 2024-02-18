#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FRAMES 100

int main() {
    int i = 1, j = 1, remainingFrames;
    
    printf("\n Enter number of frames\t:");
    scanf("%d", &remainingFrames);

    while (remainingFrames > 0) {
        printf("\n Sending frame %d", i);
        int randomValue = rand() % 15;

        if (randomValue % 5 == 0) {
            for (int waitTime = 1; waitTime < 2; waitTime++) {
                printf("\n Waiting for %d seconds\n", waitTime);
                sleep(waitTime);
            }
            printf(" Sending frame %d\n", i);
            randomValue = rand() % 10;
        }

        printf("\n Acknowledgement received for frame %d\n", j);
        remainingFrames--;
        i++;
        j++;
    }

    printf("\n End of stop-and-wait protocol \n");
    return 0;
}

