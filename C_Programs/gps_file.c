#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract_lat_lon(const char *sentence);

int main()
{
    FILE *file = fopen("gps_log.txt", "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char line[256]; // Assuming a line length of 255 characters or less

    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Remove newline character if present
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }

        extract_lat_lon(line);
    }

    fclose(file);

    return 0;
}

void extract_lat_lon(const char *sentence)
{
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
        if (sscanf(sentence, "$GPRMC,%*f,%*c,%lf,%c,%lf,%c", &latitude, &lat_direction, &longitude, &lon_direction) != 4) {
            fprintf(stderr, "Error extracting latitude and longitude from GPRMC sentence\n");
            return;
        }

        latitude *= (lat_direction == 'S') ? -1 : 1;
        longitude *= (lon_direction == 'W') ? -1 : 1;

        printf("GPRMC - Latitude: %f, Longitude: %f\n", latitude, longitude);
     /*else if (strcmp(sentence_type, "GPGGA") == 0) {
        char lat_direction, lon_direction;
        if (sscanf(sentence, "$GPGGA,,%lf,%c,%lf,%c", &latitude, &lat_direction, &longitude, &lon_direction) != 4) {
            fprintf(stderr, "Error extracting latitude and longitude from GPGGA sentence\n");
            return;
        }

        latitude *= (lat_direction == 'S') ? -1 : 1;
        longitude *= (lon_direction == 'W') ? -1 : 1; */

        printf("GPGGA - Latitude: %f, Longitude: %f\n", latitude, longitude);
  }



   
}

