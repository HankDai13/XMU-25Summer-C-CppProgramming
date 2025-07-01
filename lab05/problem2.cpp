#include <iostream>
#include <string>
using namespace std;

void inversion(int idx, int limit, string &s)
{
    // 到达交换次数上限，或左右索引重合/越界时结束
    if (idx >= limit || idx >= (int)s.length() - idx - 1) {
        cout << endl << s;
        return;
    } else {
        // 交换对应字符
        swap(s[idx], s[s.length() - idx - 1]);
        cout << s << endl;
        // 递归下一次
        inversion(idx + 1, limit, s);
    }
}

int main()
{
    int n;
    string str;
    cin >> n >> str;
    inversion(0, n, str);
    return 0;
}