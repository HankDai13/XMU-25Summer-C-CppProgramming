#include <iostream>

using namespace std;

int main()
{
    int num = 0, bin = 0;
    cin >> bin;
    for (int i = 7; i >= 0; i--)
    {
        num += (bin % 2) << i;
        bin /= 10;
    }
    cout << num;
}