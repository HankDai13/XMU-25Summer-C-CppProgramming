#include <iostream>
using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    int nums[N];
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    // 找左边界（第一个等于T的位置）
    int left = 0, right = N - 1, leftN = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < T)
            left = mid + 1;
        else
        {
            if (nums[mid] == T) leftN = mid;
            right = mid - 1;
        }
    }

    // 找右边界（最后一个等于T的位置）
    left = 0, right = N - 1;
    int rightN = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] > T)
            right = mid - 1;
        else
        {
            if (nums[mid] == T) rightN = mid;
            left = mid + 1;
        }
    }

    cout << leftN << " " << rightN << endl;
    return 0;
}