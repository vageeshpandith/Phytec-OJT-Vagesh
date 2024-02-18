#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FRAMES 100

int main() {
    int i = 1, j = 1, remainingFrames;

    printf("\n Enter number of frames\t:");
    scanf("%d", &remainingFrames);

    while (remainingFrames > 0) {
        printf("\n Sending frame %d", i);
        
        // Get the current time
        struct timespec currentTime;
        clock_gettime(CLOCK_REALTIME, &currentTime);

        // Simulate a real-time delay (e.g., 1 second)
        struct timespec delay;
        delay.tv_sec = 1;
        delay.tv_nsec = 0;

        nanosleep(&delay, NULL);

        printf("\n Sending frame %d\n", i);

        // Simulate a real-time delay for acknowledgment (e.g., 1 second)
        nanosleep(&delay, NULL);

        printf("\n Acknowledgement received for frame %d\n", j);

        remainingFrames--;
        i++;
        j++;
    }

    printf("\n End of stop-and-wait protocol \n");
    return 0;
}

