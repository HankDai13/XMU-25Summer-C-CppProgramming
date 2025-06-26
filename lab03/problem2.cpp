#include <iostream>

using namespace std;

struct node {
    int val;
    node* next;
};

node* createList() {
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
void deleteList(node*& head)
{
    int map[101] = {0};
    node *p1 = head, *p2 = nullptr;
    
    while (p1 != nullptr)
    {
        map[p1->val]++;
        p1 = p1->next;
    }
    
    p1 = head;
    while (p1 != nullptr)
    {
        if (map[p1->val] > 1)
        {
            if (p2 == nullptr) 
            {
                head = p1->next;
                delete p1;
                p1 = head;
            }
            else
            {
                p2->next = p1->next;
                delete p1;
                p1 = p2->next;
            }
        }
        else
        {
            p2 = p1;
            p1 = p1->next;
        }
    }
}
int main() {
    node* head = NULL;
    head = createList();
    deleteList(head);
    if (head == NULL) {
        cout << "NULL";
    } else {
        node* p = head;
        while (p != NULL) {
            cout << p->val << " ";
            p = p->next;
        }
    }

    return 0;
}
