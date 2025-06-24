#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[81], str2[81];
    
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;
    
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);
        
        if (c1 < c2) {
            printf("<\n");
            return 0;
        } else if (c1 > c2) {
            printf(">\n");
            return 0;
        }
        i++;
    }
    
    if (str1[i] == '\0' && str2[i] != '\0') {
        printf("<\n");
    } else if (str1[i] != '\0' && str2[i] == '\0') {
        printf(">\n");
    } else {
        printf("=\n");
    }
    
    return 0;
}