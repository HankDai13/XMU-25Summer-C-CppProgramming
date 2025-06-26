#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

// 创建链表
ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int val;
    
    while (cin >> val && val != -1) {
        ListNode* newNode = new ListNode;
        newNode->val = val;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

ListNode* findIntersection(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    int lastValue = -1;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->val == p2->val) {
            // 找到交集元素
            if (p1->val != lastValue)
            {
                lastValue = p1->val;
                ListNode* newNode = new ListNode;
                newNode->val = p1->val;
                newNode->next = nullptr;
                
                if (head == nullptr) {
                    head = tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->val < p2->val) {
            p1 = p1->next;  // p1值小，移动p1
        } else {
            p2 = p2->next;  // p2值小，移动p2
        }
    }
    
    return head;
}

int main() {
    ListNode* head1 = NULL, *head2 = NULL;
    head1 = createList();
    head2 = createList();
    ListNode* newHead = findIntersection(head1, head2);
    if (newHead == NULL) {
        cout << "-1 ";
    } else {
        ListNode* p = newHead;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
    }

    return 0;
}