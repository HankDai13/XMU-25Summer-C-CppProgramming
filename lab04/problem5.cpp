#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int z = x ^ y;
    int count = 0;
    while (z) {
        count += z & 1;
        z >>= 1;
    }
    cout << count;
}