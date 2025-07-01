#include <iostream>
#include <vector>
#include <numeric>   // for std::accumulate
#include <algorithm> // for std::max_element

using namespace std;

// 检查函数：给定一个预算值 `budget_candidate`，
// 判断是否可以在 M 组内完成所有天的分配。
bool check(long long budget_candidate, int M, int N, const vector<int>& costs) {
    int groups_needed = 1;      // 需要的组数，初始为1
    long long current_group_sum = 0; // 当前组的开销总和

    for (int i = 0; i < N; ++i) {
        // 单日开销就超过预算，这个预算肯定不行
        // (这个检查实际上被二分查找的下界保证了，但写出来更清晰)
        if (costs[i] > budget_candidate) {
            return false;
        }

        // 如果把今天的开销加进来会超出预算
        if (current_group_sum + costs[i] > budget_candidate) {
            // 那么必须开启一个新组
            groups_needed++;
            // 新组的开销从今天的算起
            current_group_sum = costs[i];
        } else {
            // 否则，可以把今天的开销加入当前组
            current_group_sum += costs[i];
        }
    }

    // 返回所需组数是否在 M 的限制之内
    return groups_needed <= M;
}

int main() {
    // 加速 C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> costs(N);
    long long total_sum = 0;
    int max_cost = 0;
    for (int i = 0; i < N; ++i) {
        cin >> costs[i];
        total_sum += costs[i];
        if (costs[i] > max_cost) {
            max_cost = costs[i];
        }
    }

    // 二分查找的范围
    long long left = max_cost;     // 预算至少要能容纳单日最大开销
    long long right = total_sum;   // 预算最多是所有开销总和（当 M=1 时）
    long long ans = right;         // 存储最终答案

    while (left <= right) {
        long long mid = left + (right - left) / 2; // 防止溢出

        // 检查 mid 这个预算值是否可行
        if (check(mid, M, N, costs)) {
            // 如果可行，说明 mid 是一个潜在的答案
            // 我们尝试寻找更小的预算
            ans = mid;
            right = mid - 1;
        } else {
            // 如果不可行，说明预算太小了，需要提高
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
