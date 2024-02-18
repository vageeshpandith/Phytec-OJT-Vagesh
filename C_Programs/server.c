#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_USERS 10

struct User {
    char username[50];
    char password[50];
};

struct File {
    char filename[50];
    char content[BUFFER_SIZE];
};

struct User users[MAX_USERS];
struct File files[MAX_USERS];

// Function to authenticate user
int authenticate_user(char* username, char* password) {
    for (int i = 0; i < MAX_USERS; ++i) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1; // Authentication successful
        }
    }
    return 0; // Authentication failed
}

// Function to handle client requests
void handle_client(int client_socket) {
    char username[50];
    char password[50];

    // Receive username and password from the client
    recv(client_socket, username, sizeof(username), 0);
    recv(client_socket, password, sizeof(password), 0);

    // Authenticate the user
    if (authenticate_user(username, password)) {
        send(client_socket, "Authentication successful", sizeof("Authentication successful"), 0);

        // Send file list to the client
        for (int i = 0; i < MAX_USERS; ++i) {
            send(client_socket, files[i].filename, sizeof(files[i].filename), 0);
        }

        // Receive file selection from the client
        char selected_file[50];
        recv(client_socket, selected_file, sizeof(selected_file), 0);

        // Find the selected file and send its content
        for (int i = 0; i < MAX_USERS; ++i) {
            if (strcmp(files[i].filename, selected_file) == 0) {
                send(client_socket, files[i].content, sizeof(files[i].content), 0);
                break;
            }
        }
    } else {
        send(client_socket, "Authentication failed", sizeof("Authentication failed"), 0);
    }

    close(client_socket);
}

int main() {
    // Initialize users (for demonstration purposes)
    strcpy(users[0].username, "user1");
    strcpy(users[0].password, "pass1");

    // Initialize files (for demonstration purposes)
    strcpy(files[0].filename, "file1.txt");
    strcpy(files[0].content, "Content of file1.txt");

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) == -1) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle client requests
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}

