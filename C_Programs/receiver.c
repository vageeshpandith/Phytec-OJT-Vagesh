#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 1, j = 1, remainingFrames = 5;  // Adjust the number of frames as needed

    while (remainingFrames > 0) {
        // Simulate receiving a frame (replace sleep with actual reception)
        sleep(1);

        printf("\n Acknowledging frame %d", i);

        // Simulate processing the frame (replace sleep with actual processing)
        sleep(1);

        printf("\n Frame %d processed\n", j);

        remainingFrames--;
        i++;
        j++;
    }

    printf("\n End of reception\n");
    return 0;
}

