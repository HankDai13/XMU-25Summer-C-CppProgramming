#include <iostream>
#include <string>
using namespace std;

const int MAXM = 100000 + 5;
int Lft[MAXM], Rgt[MAXM], val_node[MAXM];
int idx = 0;  // 下一个新节点下标

// 在 l 和 r 之间插入值为 x 的新节点
void add(int l, int r, int x) {
    int cur = ++idx;
    val_node[cur] = x;
    Lft[cur] = l;  Rgt[cur] = r;
    Rgt[l] = cur;  Lft[r] = cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 初始化 双向链表的哨兵节点 0
    Lft[0] = Rgt[0] = 0;

    int M;
    cin >> M;
    string cmd;
    while (M--) {
        cin >> cmd;
        if (cmd == "L") {
            int x; cin >> x;
            // 在最左侧插入：在 0 和 Rgt[0] 之间
            add(0, Rgt[0], x);
        }
        else if (cmd == "R") {
            int x; cin >> x;
            // 在最右侧插入：在 Lft[0] 和 0 之间
            add(Lft[0], 0, x);
        }
        else if (cmd == "D") {
            int k; cin >> k;
            // 删除第 k 个插入的节点
            Rgt[Lft[k]] = Rgt[k];
            Lft[Rgt[k]] = Lft[k];
        }
        else if (cmd == "IL") {
            int k, x; cin >> k >> x;
            // 在第 k 个节点左侧插入：在 Lft[k] 和 k 之间
            add(Lft[k], k, x);
        }
        else if (cmd == "IR") {
            int k, x; cin >> k >> x;
            // 在第 k 个节点右侧插入：在 k 和 Rgt[k] 之间
            add(k, Rgt[k], x);
        }
    }

    // 输出从左到右的所有节点
    int cur = Rgt[0];
    bool first = true;
    while (cur != 0) {
        if (!first) cout << ' ';
        cout << val_node[cur];
        first = false;
        cur = Rgt[cur];
    }
}