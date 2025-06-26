#include <iostream>

// 节点结构体
struct node {
    int row, col, val;
    node* next;
};

// ----------------- 核心辅助函数 -----------------

// 函数1: 插入或覆盖节点 (用于处理矩阵内部的重复)
// 在有序链表head中，处理一个新元素(r,c,v)。如果(r,c)已存在，则用v覆盖它的值；如果不存在，则在正确位置插入新节点。
void insertOrOverwrite(node* head, int r, int c, int v) {
    node* prev = head;
    node* curr = head->next;

    // 查找位置
    while (curr != nullptr && (curr->row < r || (curr->row == r && curr->col < c))) {
        prev = curr;
        curr = curr->next;
    }

    // 检查是否是相同位置
    if (curr != nullptr && curr->row == r && curr->col == c) {
        // 位置相同，执行覆盖
        curr->val = v;
    } else {
        // 位置不同，插入新节点
        node* newNode = new node;
        newNode->row = r;
        newNode->col = c;
        newNode->val = v;
        newNode->next = curr;
        prev->next = newNode;
        head->val++; // 只有插入新节点时，总数才增加
    }
}

// 函数2: 合并并相加两个有序链表 (用于处理矩阵间的合并)
node* mergeAndAdd(node* headA, node* headB) {
    // 创建结果C的头节点
    node* headC = new node{headA->row, headA->col, 0, nullptr};
    node* tailC = headC; // 尾指针，用于高效添加

    node* pA = headA->next;
    node* pB = headB->next;

    while (pA != nullptr && pB != nullptr) {
        if (pA->row < pB->row || (pA->row == pB->row && pA->col < pB->col)) {
            // A的节点靠前，复制A的节点
            tailC->next = new node{pA->row, pA->col, pA->val, nullptr};
            pA = pA->next;
        } else if (pB->row < pA->row || (pB->row == pA->row && pB->col < pA->col)) {
            // B的节点靠前，复制B的节点
            tailC->next = new node{pB->row, pB->col, pB->val, nullptr};
            pB = pB->next;
        } else {
            // 位置相同，相加
            int sum = pA->val + pB->val;
            if (sum != 0) {
                tailC->next = new node{pA->row, pA->col, sum, nullptr};
            } else {
                // 和为0，跳过这个节点，并且不移动tailC
                pA = pA->next;
                pB = pB->next;
                continue; 
            }
            pA = pA->next;
            pB = pB->next;
        }
        tailC = tailC->next;
        headC->val++;
    }

    // 添加A或B中剩余的节点
    node* remainder = (pA != nullptr) ? pA : pB;
    while (remainder != nullptr) {
        tailC->next = new node{remainder->row, remainder->col, remainder->val, nullptr};
        tailC = tailC->next;
        headC->val++;
        remainder = remainder->next;
    }

    return headC;
}


// ----------------- 其他辅助函数 -----------------

void deleteList(node* head) {
    node* current = head;
    while (current != nullptr) {
        node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void printList(node* head) {
    if (head == nullptr) return;
    std::cout << head->row << " " << head->col << " " << head->val << std::endl;
    node* p = head->next;
    while (p != nullptr) {
        std::cout << p->row << " " << p->col << " " << p->val << std::endl;
        p = p->next;
    }
}

// ----------------- 主函数 -----------------

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int rows, cols;
    std::cin >> rows >> cols;

    // 步骤1：处理矩阵A，得到内部无重复的有序链表 headA
    node* headA = new node{rows, cols, 0, nullptr};
    int n1;
    std::cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int r, c, v;
        std::cin >> r >> c >> v;
        insertOrOverwrite(headA, r, c, v);
    }

    // 步骤2：处理矩阵B，得到内部无重复的有序链表 headB
    node* headB = new node{rows, cols, 0, nullptr};
    int n2;
    std::cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int r, c, v;
        std::cin >> r >> c >> v;
        insertOrOverwrite(headB, r, c, v);
    }

    // 步骤3：合并相加两个处理好的链表
    node* headC = mergeAndAdd(headA, headB);

    printList(headC);
    
    // 清理所有内存
    deleteList(headA);
    deleteList(headB);
    deleteList(headC);

    return 0;
}