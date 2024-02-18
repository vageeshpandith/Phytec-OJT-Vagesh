#include <stdio.h>

int main() {
    // Define a buffer as an array of characters
    char buffer[100]; // You can adjust the size based on your needs

    // Read input into the buffer
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Display the content of the buffer
    printf("You entered: %s", buffer);

    return 0;
}

