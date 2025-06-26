#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建链表
ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int val;
    
    while (cin >> val && val != -1) {
        ListNode* newNode = new ListNode(val);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// 输出链表
void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "-1" << endl;
        return;
    }
    
    bool first = true;
    while (head != nullptr) {
        if (!first) cout << " ";
        cout << head->val;
        first = false;
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = createList();
    
    if (head == nullptr) {
        cout << "-1" << endl;
        cout << "-1" << endl;
        return 0;
    }
    
    // 分别构建奇数和偶数链表
    ListNode* oddHead = nullptr;
    ListNode* oddTail = nullptr;
    ListNode* evenHead = nullptr;
    ListNode* evenTail = nullptr;
    
    ListNode* curr = head;
    int index = 1;  // 从1开始计数
    
    while (curr != nullptr) {
        ListNode* newNode = new ListNode(curr->val);
        
        if (index % 2 == 1) {  // 奇数位置
            if (oddHead == nullptr) {
                oddHead = oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else {  // 偶数位置
            if (evenHead == nullptr) {
                evenHead = evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        
        curr = curr->next;
        index++;
    }
    
    // 分别输出两个链表
    printList(oddHead);
    printList(evenHead);
    
    return 0;
}