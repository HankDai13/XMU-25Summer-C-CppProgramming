#include <stdio.h>
#include <string.h>

int main() {
    char str[20], substr[10];
    
    while (scanf("%s %s", str, substr) == 2) {
        int len = strlen(str);
        int max_pos = 0;
        char max_char = str[0];
        
        // 找到ASCII码最大的字符的第一个位置
        for (int i = 1; i < len; i++) {
            if (str[i] > max_char) {
                max_char = str[i];
                max_pos = i;
            }
        }
        
        // 在最大字符后面插入substr
        for (int i = 0; i <= max_pos; i++) {
            printf("%c", str[i]);
        }
        printf("%s", substr);
        for (int i = max_pos + 1; i < len; i++) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
    
    return 0;
}