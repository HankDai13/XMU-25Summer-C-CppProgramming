#include <iostream>
#include <iomanip>
using namespace std;

double GetDoubleFromString(char * str)
{
    static char* current = nullptr;
    
    if (str != nullptr) {
        current = str;
    }
    
    if (current == nullptr) {
        return -1;
    }
    
    // 跳过非数字字符
    while (*current != '\0' && !(*current >= '0' && *current <= '9') && *current != '.') {
        current++;
    }
    
    if (*current == '\0') {
        return -1;
    }
    
    // 开始解析数字
    double result = 0.0;
    double decimal = 0.1;
    bool hasDecimal = false;
    
    // 解析整数部分
    while (*current >= '0' && *current <= '9') {
        result = result * 10 + (*current - '0');
        current++;
    }
    
    // 处理小数点
    if (*current == '.') {
        hasDecimal = true;
        current++;
        
        // 解析小数部分
        while (*current >= '0' && *current <= '9') {
            result += (*current - '0') * decimal;
            decimal /= 10;
            current++;
        }
    }
    
    return result;
}

int main()
{
    char line[300];
    while(cin.getline(line,280)) {
        double n;
        n = GetDoubleFromString(line);
        while( n > 0) {
            cout << fixed << setprecision(6) << n << endl;
            n = GetDoubleFromString(NULL);
        }
    }
    return 0;
}