#include <iostream>

using namespace std;

struct node {
    int row, col, val;
    node* next;
};

node* createList() {
    //请你将这个函数补充完整
    node* head = new node;
    node* tail = head;
    cin >> head->row >> head->col >> head->val;
    
    for (int i = 0; i < head->val; i++) {
        node* newNode = new node;
        newNode->next = nullptr;
        cin >> newNode->row >> newNode->col >> newNode->val;
        tail->next = newNode;
        tail = newNode;
    }
    
    return head;
}

node* transpose(node* head) {
    if (head == nullptr) return nullptr;
    
    // 创建新的头节点
    node* newHead = new node;
    newHead->row = head->col;
    newHead->col = head->row;
    newHead->val = head->val;
    newHead->next = nullptr;
    
    node* p1 = head->next;
    
    // 遍历原链表，创建转置后的节点
    while (p1 != nullptr) {
        node* newNode = new node;
        newNode->row = p1->col;  // 行列互换
        newNode->col = p1->row;
        newNode->val = p1->val;
        newNode->next = nullptr;
        
        // 找到正确的插入位置（按行优先顺序）
        node* prev = newHead;
        node* curr = newHead->next;
        
        while (curr != nullptr && 
               (curr->row < newNode->row || 
                (curr->row == newNode->row && curr->col < newNode->col))) {
            prev = curr;
            curr = curr->next;
        }
        
        // 插入新节点
        newNode->next = curr;
        prev->next = newNode;
        
        p1 = p1->next;
    }
    
    return newHead;
}
int main() {
    node* head = NULL;
    head = createList();
    head = transpose(head);
    if (head == NULL) {
        cout << "-1 ";
    } else {
        node* p = head;
        while (p != NULL) {
            cout << p->row << " " << p->col << " " << p->val << endl;
            p = p->next;
        }
    }

    return 0;
}
