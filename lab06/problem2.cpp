#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> nums(N);
    unordered_map<int,int> pos;
    pos.reserve(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    int T;
    cin >> T;
    while (T--) {
        int target;
        cin >> target;
        auto it = pos.find(target);
        if (it != pos.end()) cout << it->second << "\n";
        else cout << -1 << "\n";
    }
}