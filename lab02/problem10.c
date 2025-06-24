#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void print_substr(char* s1, int p1, int p2, int p3)
{
    char left = s1[0];   // 减号左边的字符
    char right = s1[2];  // 减号右边的字符
    
    // 输出左边字符
    printf("%c", left);
    
    // 如果右边字符是左边字符的直接后继，只删除减号
    // (因为右边字符会在主循环中打印，这里什么都不用做)
    if (right == left + 1) {
        return;
    }
    
    // 计算中间需要填充的字符个数
    int count = right - left - 1;
    
    if (p1 == 3) {
        // 用星号填充：总共 count * p2 个星号
        int total_stars = count * p2;
        for (int i = 0; i < total_stars; i++) {
            printf("*");
        }
    } else {
        // 生成中间的字符序列
        char* middle_chars = (char*)malloc((count + 1) * sizeof(char));
        
        for (int i = 0; i < count; i++) {
            char ch = left + 1 + i;
            
            if (ch >= 'a' && ch <= 'z') {
                // 字母处理
                if (p1 == 1) {
                    middle_chars[i] = ch;  // 小写字母
                } else if (p1 == 2) {
                    middle_chars[i] = ch - 'a' + 'A';  // 转为大写字母
                }
            } else {
                // 数字保持不变
                middle_chars[i] = ch;
            }
        }
        
        // 根据p3决定输出顺序
        if (p3 == 1) {
            // 正序输出
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < p2; j++) {
                    printf("%c", middle_chars[i]);
                }
            }
        } else if (p3 == 2) {
            // 逆序输出
            for (int i = count - 1; i >= 0; i--) {
                for (int j = 0; j < p2; j++) {
                    printf("%c", middle_chars[i]);
                }
            }
        }
        
        free(middle_chars);
    }
    
}

int need_str(char* s1)
{
    if ((islower(s1[0]) && islower(s1[2])) || (isdigit(s1[0]) && isdigit(s1[2])))
    {
        if (s1[0] < s1[2])
        {
            return 1;
        }
    }
    return 0;   // 其他情况都不展开
}

int main()
{
    int p1, p2, p3;
    scanf("%d %d %d", &p1, &p2, &p3);
    char str[101];
    scanf("%s", str);
    
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        // 检查是否可能是减号模式 (需要至少3个字符：x-y)
        if (i + 2 < len && str[i+1] == '-')
        {
            char substr[4];
            substr[0] = str[i];
            substr[1] = str[i+1];
            substr[2] = str[i+2];
            substr[3] = '\0';
            
            int mode = need_str(substr);
            if (mode == 1)
            {
                print_substr(substr, p1, p2, p3);
                i += 1;  // 只跳过减号，右边字符留给下一次循环处理
            }
            else
            {
                printf("%c", str[i]);  // 只输出当前字符
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    
    return 0;
}