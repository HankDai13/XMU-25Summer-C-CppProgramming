#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char votes[1000][27];
    int count = 0;
    char buffer[26000];
    
    // 读取整行
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return 0;
    
    // 解析输入格式 ["ABC","DEF",...]
    char *start = strchr(buffer, '[');
    if (start == NULL) return 0;
    start++; // 跳过 '['
    
    char *token = strtok(start, "\",]");
    while (token != NULL && count < 1000) {
        // 跳过空白字符
        while (*token == ' ' || *token == '\t') token++;
        if (strlen(token) > 0 && token[0] >= 'A' && token[0] <= 'Z') {
            strcpy(votes[count], token);
            count++;
        }
        token = strtok(NULL, "\",]");
    }
    
    if (count == 0) return 0;
    
    int n = strlen(votes[0]);
    
    // 获取所有公司字符
    char companies[27];
    int company_count = 0;
    int used[26] = {0};
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < n; j++) {
            char c = votes[i][j];
            if (!used[c - 'A']) {
                companies[company_count++] = c;
                used[c - 'A'] = 1;
            }
        }
    }
    
    // 统计每个公司在每个位置的得票数
    int position_votes[26][26] = {0}; // position_votes[company][position]
    
    for (int i = 0; i < count; i++) {
        for (int pos = 0; pos < n; pos++) {
            char company = votes[i][pos];
            position_votes[company - 'A'][pos]++;
        }
    }
    
    // 排序公司
    for (int i = 0; i < company_count - 1; i++) {
        for (int j = i + 1; j < company_count; j++) {
            char comp1 = companies[i];
            char comp2 = companies[j];
            
            int should_swap = 0;
            
            // 比较每个位置的得票数
            for (int pos = 0; pos < n; pos++) {
                int votes1 = position_votes[comp1 - 'A'][pos];
                int votes2 = position_votes[comp2 - 'A'][pos];
                
                if (votes1 < votes2) {
                    should_swap = 1;
                    break;
                } else if (votes1 > votes2) {
                    break;
                }
                // 如果相等，继续比较下一个位置
            }
            
            // 如果所有位置都相等，按字母顺序排序
            if (!should_swap) {
                int all_equal = 1;
                for (int pos = 0; pos < n; pos++) {
                    if (position_votes[comp1 - 'A'][pos] != position_votes[comp2 - 'A'][pos]) {
                        all_equal = 0;
                        break;
                    }
                }
                if (all_equal && comp1 > comp2) {
                    should_swap = 1;
                }
            }
            
            if (should_swap) {
                char temp = companies[i];
                companies[i] = companies[j];
                companies[j] = temp;
            }
        }
    }
    
    // 输出结果
    companies[company_count] = '\0';
    printf("\"%s\"\n", companies);
    
    return 0;
}
