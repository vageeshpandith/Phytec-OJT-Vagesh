#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>    
#include <unistd.h>

void extract_lat_lon(const char *sentence) {
    char sentence_type[7];
    double latitude, longitude;

    // Parse sentence type (e.g., GPRMC, GPGGA)
    if (sscanf(sentence, "$%6[^,]", sentence_type) != 1) {
        fprintf(stderr, "Error parsing sentence type\n");
        return;
    }

    // Extract latitude and longitude based on sentence type
    if (strcmp(sentence_type, "GPRMC") == 0) {
        char lat_direction, lon_direction;
        if (sscanf(sentence, "$GPRMC,,,%lf,%c,%lf,%c", &latitude, &lat_direction, &longitude, &lon_direction) != 4) {
            fprintf(stderr, "Error extracting latitude and longitude from GPRMC sentence\n");
            return;
        }

        latitude *= (lat_direction == 'S') ? -1 : 1;
        longitude *= (lon_direction == 'W') ? -1 : 1;

        printf("GPRMC - Latitude: %f, Longitude: %f\n", latitude, longitude);
    } else if (strcmp(sentence_type, "GPGGA") == 0) {
        char lat_direction, lon_direction;
        if (sscanf(sentence, "$GPGGA,,,%lf,%c,%lf,%c", &latitude, &lat_direction, &longitude, &lon_direction) != 4) {
            fprintf(stderr, "Error extracting latitude and longitude from GPGGA sentence\n");
            return;
        }

        latitude *= (lat_direction == 'S') ? -1 : 1;
        longitude *= (lon_direction == 'W') ? -1 : 1;

        printf("GPGGA - Latitude: %f, Longitude: %f\n", latitude, longitude);
    }
}

int main() 
{
    const char *serial_port = "/dev/ttyUSB0";  // Change this to your actual serial port

    int serial_fd = open(serial_port, O_RDWR | O_NOCTTY);
    if (serial_fd < 0) {
        perror("Error opening serial port");
        return 1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(struct termios));

    if (tcgetattr(serial_fd, &tty) != 0) {
        perror("Error from tcgetattr");
        return 1;
    }

    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cflag |= CREAD | CLOCAL;

    tty.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);
    tty.c_oflag = 0;
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

    tty.c_cc[VMIN] = 1;
    tty.c_cc[VTIME] = 0;

    if (tcsetattr(serial_fd, TCSANOW, &tty) != 0) {
        perror("Error from tcsetattr");
        return 1;
    }

    while (1) {
        char buffer[256];
        ssize_t read_len = read(serial_fd, buffer, sizeof(buffer) - 1);
        if (read_len > 0) {
            buffer[read_len] = '\0';  // Null-terminate the received data
            extract_lat_lon(buffer);
        }
    }

    close(serial_fd);

    return 0;
}
