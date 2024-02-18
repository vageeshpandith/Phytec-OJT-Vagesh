#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_tcp_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    return sockfd;
}

void send_request(int sockfd, const char *host, const char *path) {
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Error sending request");
    }
}

void receive_response(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    ssize_t n;
    while ((n = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n < 0) {
        error("Error receiving response");
    }
}

int main() {
    const char *host = "www.example.com";
    const char *path = "/index.html";
    int port = 80;

    struct sockaddr_in server_addr;
    struct hostent *server;

    int sockfd = create_tcp_socket();

    server = gethostbyname(host);
    if (server == NULL) {
        error("Error, no such host");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    send_request(sockfd, host, path);
    receive_response(sockfd);

    close(sockfd);

    return 0;
}

