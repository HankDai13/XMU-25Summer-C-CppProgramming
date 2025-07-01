#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// 使用 long long 防止整数溢出
using namespace std;

// 定义一个结构体来存储每组防具的信息，比使用多个数组更清晰
struct DefenseGroup {
    long long S, E, D;
};

// 计算在 [0, pos] 区间内防具的总数
// 这是二分查找的核心辅助函数
long long countPrefix(long long pos, int N, const vector<DefenseGroup>& defenses) {
    long long total_count = 0;
    for (int i = 0; i < N; ++i) {
        // 如果这组防具的起点就在 pos 之后，那它在 [0, pos] 区间内肯定没有贡献
        if (defenses[i].S > pos) {
            continue;
        }

        // --- 开始处理有贡献的防具组 ---

        // 特殊情况：公差为 0
        if (defenses[i].D == 0) {
            // D 为 0，意味着只有一个防具在 S[i] 点。
            // 因为已经通过了上面的 if (S[i] > pos) 判断，
            // 所以我们确信 S[i] <= pos，即这个点在 [0, pos] 范围内。
            // 因此，它贡献了 1 个防具。
            total_count += 1;
        } else {
            // 一般情况：公差不为 0
            // 计算这组防具在 [0, pos] 区间内的实际终点
            long long real_end = min(defenses[i].E, pos);
            // 使用等差数列项数公式计算数量
            total_count += (real_end - defenses[i].S) / defenses[i].D + 1;
        }
    }
    return total_count;
}

// 主解决函数
void solve() {
    int N;
    cin >> N;
    vector<DefenseGroup> defenses(N);
    long long max_e = 0; // 找到所有防具覆盖的最大坐标，作为二分查找的右边界
    for (int i = 0; i < N; ++i) {
        cin >> defenses[i].S >> defenses[i].E >> defenses[i].D;
        if (defenses[i].E > max_e) {
            max_e = defenses[i].E;
        }
    }

    // --- 预检查 ---
    // 计算整个防线上的防具总数。如果总数是偶数，根据题意肯定没有破绽。
    if (countPrefix(max_e, N, defenses) % 2 == 0) {
        cout << "There's no weakness." << endl;
        return;
    }

    // --- 二分查找破绽位置 P ---
    long long left = 0, right = max_e;
    long long P = 0; // 存储最终破绽位置

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        // 检查 [0, mid] 区间内防具总数的奇偶性
        if (countPrefix(mid, N, defenses) % 2 != 0) {
            // 如果是奇数，说明破绽点在 [0, mid] 这个区间内
            // 我们记录下这个可能的答案，并尝试在更小的范围 [left, mid-1] 内寻找
            P = mid;
            right = mid - 1;
        } else {
            // 如果是偶数，说明破绽点在 (mid, right] 这个区间内
            left = mid + 1;
        }
    }

    // --- 计算 P 点的防具数量 C ---
    int C = 0;
    for (int i = 0; i < N; ++i) {
        // 条件1: P 必须在防具的覆盖范围 [S, E] 内
        if (P >= defenses[i].S && P <= defenses[i].E) {
            // 条件2: P 必须是该等差数列的一项
            if (defenses[i].D == 0) {
                // 特殊情况：公差为 0
                if (P == defenses[i].S) {
                    C++;
                }
            } else {
                // 一般情况：公差不为 0
                if ((P - defenses[i].S) % defenses[i].D == 0) {
                    C++;
                }
            }
        }
    }

    cout << P << " " << C << endl;
}

int main() {
    // 加速 C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}