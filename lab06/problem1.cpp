#include <iostream>

using namespace std;


int main()
{
    int N;
    cin >> N;
    int nums[N] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    // 获取旋转下标
    int rollIndex = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (nums[i+1] < nums[i])
        {
            rollIndex = i;
            break;
        }
    }
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int target;
        cin >> target;
        if (target > nums[N-1])
        {
            int found = 0;
            for (int i = 0; i <= rollIndex; i++)
            {
                if (nums[i] == target)
                {
                    cout << i << endl;
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                cout << -1 << endl;
            }
        }
        else
        {
            int found = 0;
            for (int i = rollIndex + 1; i < N; i++)
            {
                if (nums[i] == target)
                {
                    cout << i << endl;
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}