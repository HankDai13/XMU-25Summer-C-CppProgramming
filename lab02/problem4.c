#include <stdio.h>
#include <string.h>

int main() {
    char s1[31], s2[31];
    scanf("%s %s", s1, s2);
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create doubled strings to check all possible rotations
    char doubled_s1[61], doubled_s2[61];
    strcpy(doubled_s1, s1);
    strcat(doubled_s1, s1);
    strcpy(doubled_s2, s2);
    strcat(doubled_s2, s2);
    
    // Check if s1 is substring of any rotation of s2
    if (strstr(doubled_s2, s1) != NULL) {
        printf("true\n");
        return 0;
    }
    
    // Check if s2 is substring of any rotation of s1
    if (strstr(doubled_s1, s2) != NULL) {
        printf("true\n");
        return 0;
    }
    
    printf("false\n");
    return 0;
}