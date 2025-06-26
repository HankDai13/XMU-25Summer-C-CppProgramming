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

int main() {
    node* head = NULL;
    head = createList();

    if (head == NULL) {
        cout << "-1 ";
    } else {
        node* p = head;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
    }

    return 0;
}
