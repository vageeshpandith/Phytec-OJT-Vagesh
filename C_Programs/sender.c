#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i = 1, j = 1, remainingFrames = 5;  // Adjust the number of frames as needed

    while (remainingFrames > 0) {
        printf("\n Sending frame %d", i);

        // Simulate waiting for acknowledgment (replace sleep with actual wait)
        sleep(2);

        printf("\n Acknowledgement received for frame %d\n", j);

        remainingFrames--;
        i++;
        j++;
    }

    printf("\n End of transmission\n");
    return 0;
}
