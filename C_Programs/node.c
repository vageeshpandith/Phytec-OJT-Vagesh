#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void extract_lat_lon(const char *sentence) {
    regex_t regex;
    regmatch_t match[6];

    // Define the regular expression pattern
    const char *pattern = "\\$G[PN][GLVTA].*?([0-9]+\\.[0-9]+),([NS]),([0-9]+\\.[0-9]+),([EW])";
    
    // Compile the regular expression
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Failed to compile regular expression\n");
        return;
    }

    // Execute the regular expression
    if (regexec(&regex, sentence, 6, match, 0) == 0) {
        double latitude = atof(sentence + match[1].rm_so);
        latitude *= (sentence[match[2].rm_so] == 'S') ? -1 : 1;

        double longitude = atof(sentence + match[3].rm_so);
        longitude *= (sentence[match[4].rm_so] == 'W') ? -1 : 1;

        printf("Latitude: %f, Longitude: %f\n", latitude, longitude);
    } else {
        printf("Invalid data\n");
    }

    // Free the compiled regular expression
    regfree(&regex);
}

int main() {
    // Simulating real-time NMEA sentence input (replace this with actual input)
    const char *nmea_sentences[] = {
        "$GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A",
        "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*42",
    };

    for (int i = 0; i < sizeof(nmea_sentences) / sizeof(nmea_sentences[0]); i++) {
        extract_lat_lon(nmea_sentences[i]);
    }

    return 0;
}
