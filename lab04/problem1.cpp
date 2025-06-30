#include <iostream>
using namespace std;

int main() {
    int num, res = 0;
    while (cin >> num) {
        res ^= num;
    }
    cout << res << endl;
    return 0;
}