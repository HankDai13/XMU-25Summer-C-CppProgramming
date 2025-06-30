#include <iostream>

using namespace std;


int main()
{
    int num = 0, count = 0;
    cin >> num;
    while (num > 0)
    {
        if (num % 2 == 1)
        {
            count++;
        }
        num /= 2;
    }
    cout << count;
    return 0;
}