#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int M;
    cin >> M;
    int target;
    for (int m = 0; m < M; m++)
    {
        cin >> target;
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (nums[left] == target)
        {
            right = left + 1;
            while (nums[right] == target)
            {
                right++;
            }
            if (right > n - 1)
            {
                cout << nums[left - 1] << endl;
            }
            else if (nums[right] - target < target - nums[left - 1])
            {
                cout << nums[right] << endl;
            }
            else
            {
                cout << nums[left - 1] << endl;
            }
        }
        else
        {
            if (left == 0 || nums[left] - target < target - nums[left - 1])
            {
                cout << nums[left] << endl;
            }
            else
            {
                cout << nums[left - 1] << endl;
            }
        }
    }
    return 0;
}