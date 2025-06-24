#include <stdio.h>
#include <string.h>

// 辅助函数：用于反转字符串的指定部分
// [start, end] 是一个左闭右闭区间
void reverse(char* start, char* end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    // 设定一个足够大的缓冲区来存储字符串
    char s[1001]; 
    int n;

    // 1. 读取输入
    // 使用格式串 "%[^\"]" 来读取并存储双引号内的所有内容
    // 第一个 \" 匹配开头的引号，最后的 \" (在格式串外) 被 scanf 留在输入缓冲区
    scanf("\"%[^\"]\"", s);
    scanf("%d", &n);

    // 获取字符串长度
    int len = strlen(s);

    // 2. 核心操作：三次反转法
    if (len > 0 && n > 0) {
        // 确保 n 在有效范围内
        n = n % len; 

        // 第一次反转：反转前 n 个字符
        // s 是起始地址, s + n - 1 是第 n 个字符的地址
        reverse(s, s + n - 1);

        // 第二次反转：反转从第 n 个字符到末尾的部分
        // s + n 是第 n+1 个字符的地址, s + len - 1 是最后一个字符的地址
        reverse(s + n, s + len - 1);

        // 第三次反转：反转整个字符串
        reverse(s, s + len - 1);
    }
    
    // 3. 格式化输出
    printf("%s\n", s);

    return 0;
}