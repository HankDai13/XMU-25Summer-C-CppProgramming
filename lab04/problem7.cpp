#include <iostream>
#include <string>

using namespace std;

string decToBin(long long num)
{
    if (num == 0) {
        return string(32, '0');
    }
    string res = "";
    while (num > 0) {
        res = char('0' + num % 2) + res;
        num /= 2;
    }
    res = string(32 - res.length(), '0') + res;
    return res;
}

long long binToDec(string num)
{
    long long result = 0;
    
    for (char bit : num) {
        result = (result << 1) + (bit - '0');
    }
    
    return result;
}
int main()
{
    long long num;
    cin >> num;
    string numStr = decToBin(num);
    numStr = numStr.substr(16, 16) + numStr.substr(0, 16);
    cout << binToDec(numStr);
    return 0;
}

