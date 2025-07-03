#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int n = 0; n < N; n++)
    {
        cin >> nums[n];
    }
    
    vector<int> original = nums; // 备份原数组
    
    for (int m = 0; m < M; m++)
    {
        int left, right, k;
        cin >> left >> right >> k;
        
        // 每次查询前恢复原数组
        copy(original.begin() + left - 1, original.begin() + right, 
             nums.begin() + left - 1);
        
        nth_element(nums.begin() + left - 1, 
                   nums.begin() + left + k - 2, 
                   nums.begin() + right);
        
        cout << nums[left + k - 2] << endl;
    }
    return 0;
}