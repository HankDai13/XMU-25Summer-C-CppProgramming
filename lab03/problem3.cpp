#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

node* createList() {
    //请你将这个函数补充完整
    node* head = NULL;
    node* tail = NULL;
    int value;
    
    while (cin >> value && value != -1) {
        node* newNode = new node;
        newNode->val = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}


node* reverseList(node* head) {
    // 请你将这个函数补充完整
    node* newhead = nullptr, *p1 = head;

    while (p1 != nullptr)
    {
        node* newNode = new node;
        newNode->val = p1->val;
        newNode->next = newhead;
        newhead = newNode;
        p1 = p1->next;
    }

    return newhead;
}

int main() {
    node* head = NULL;
    head = createList();
    
    node* head1 = NULL;
    head1 = reverseList(head);
    
    if (head1 == NULL) {
        cout << "-1 ";
    } else {
        node* p = head1;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
    }
    
    return 0;
}
