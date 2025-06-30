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
    if (count == 1)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}