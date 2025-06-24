#include <stdio.h>
#include <string.h>
#include <limits.h>

#define min(a,b) ((a)<(b)?(a):(b))

int main() {
    int n;
    scanf("%d", &n);
    
    char s[100001];
    scanf("%s", s);
    
    int a[100001];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // target字符串
    char target[] = "jxnu";
    
    // dp[i][j] = 处理完前i个字符，匹配状态为j的最小代价
    long long dp[100001][4];
    
    // 初始化为无穷大
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }
    
    // 初始状态：没处理任何字符，匹配状态为0
    dp[0][0] = 0;
    
    // 动态规划
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (dp[i][j] == LLONG_MAX) continue;
            
            // 选择1：删除第i个字符
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i]);
            
            // 选择2：保留第i个字符
            if (s[i] == target[j]) {
                // 匹配到下一个字符
                if (j + 1 < 4) {  // 确保不会形成完整的"jxnu"
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                }
                // 如果j+1==4，意味着形成"jxnu"，不允许这种转移
            } else {
                // 不匹配目标字符，状态保持不变
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
        }
    }
    
    // 答案是所有可能的最终状态中的最小值
    long long ans = LLONG_MAX;
    for (int j = 0; j < 4; j++) {
        ans = min(ans, dp[n][j]);
    }
    
    printf("%lld\n", ans);
    return 0;
}