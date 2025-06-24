#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static char *current_pos = NULL;

double GetDoubleFromString(char *str)
{
    if (str != NULL) {
        current_pos = str;
    }
    
    if (current_pos == NULL) {
        return -1.0;
    }
    
    // Skip non-digit characters
    while (*current_pos && !isdigit(*current_pos)) {
        current_pos++;
    }
    
    // If we've reached the end, no more numbers
    if (*current_pos == '\0') {
        return -1.0;
    }
    
    // Extract the number
    char *end_pos;
    double result = strtod(current_pos, &end_pos);
    
    // Move current_pos to after the number
    current_pos = end_pos;
    
    return result;
}

int main()
{
    char line[300];
    while (fgets(line, sizeof(line), stdin)) {
        double n;
        n = GetDoubleFromString(line);
        while (n > 0) {
            printf("%.6f\n", n);
            n = GetDoubleFromString(NULL);
        }
    }
    return 0;
}