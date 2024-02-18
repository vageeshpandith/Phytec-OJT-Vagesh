#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create a socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Provide username and password for authentication
    char username[50] = "user1";
    char password[50] = "pass1";
    send(client_socket, username, sizeof(username), 0);
    send(client_socket, password, sizeof(password), 0);

    // Receive authentication response from the server
    char auth_response[50];
    recv(client_socket, auth_response, sizeof(auth_response), 0);
    printf("Authentication Response: %s\n", auth_response);

    if (strcmp(auth_response, "Authentication successful") == 0) {
        // Receive file list from the server
        printf("Available Files:\n");
        char file_name[50];
        while (1) {
            recv(client_socket, file_name, sizeof(file_name), 0);
            if (strlen(file_name) == 0) {
                break;
            }
            printf("- %s\n", file_name);
        }

        // Select a file to download
        char selected_file[50] = "file1.txt";
        send(client_socket, selected_file, sizeof(selected_file), 0);

        // Receive file content from the server
        char file_content[BUFFER_SIZE];
        recv(client_socket, file_content, sizeof(file_content), 0);
        printf("\nFile Content:\n%s\n", file_content);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}

