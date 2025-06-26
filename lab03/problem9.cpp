#include <iostream>

using namespace std;

struct node {
    int row, col, val;
    node* next;
};

node* createList(node* head) {  
    node* tail = head;
    for (int i = 0; i < head->val; i++) {
        node* newNode = new node;
        newNode->next = nullptr;
        cin >> newNode->row >> newNode->col >> newNode->val;
        tail->next = newNode;
        tail = newNode;
    }
    
    return head;
}

node* addLists(node* headA, node* headB)
{
    node* newHead = new node;
    // Create new head node
    newHead->row = headA->row;
    newHead->col = headA->col;
    // Leave blank because we don't know how much nodes
    newHead->val = 0;
    newHead->next = nullptr;
    int count = 0;
    node* p1 = headA->next;
    node* p2 = headB->next;
    while (p1 != nullptr)
    {
        node* newNode = new node;
        newNode->row = p1->row;
        newNode->col = p1->col;
        newNode->val = p1->val;
        count++;
        p1 = p1->next;
        // 找到正确的插入位置（按行优先顺序）
        node* prev = newHead;
        node* curr = newHead->next;
    
        while (curr != nullptr && 
                (curr->row < newNode->row || 
                (curr->row == newNode->row && curr->col < newNode->col))) 
        {
            prev = curr;
            curr = curr->next;
        }        
        // 插入新节点
        newNode->next = curr;
        prev->next = newNode;

            
    }
    while (p2 != nullptr)
    {
        // 找到正确的插入位置（按行优先顺序）
        node* prev = newHead;
        node* curr = newHead->next;
    
        while (curr != nullptr && 
                (curr->row < p2->row || 
                (curr->row == p2->row && curr->col < p2->col))) 
        {
            prev = curr;
            curr = curr->next;
        }        
        if (curr != nullptr && p2->row == curr->row && p2->col == curr->col)
        {
            if (curr->val + p2->val == 0)
            {
                // Delete
                prev->next = curr->next;
                delete curr;
                curr = nullptr;
                count--;
            }
            else
            {
                curr->val += p2->val;
            }
        }
        else
        {
            node* newNode = new node;
            newNode->row = p2->row;
            newNode->col = p2->col;
            newNode->val = p2->val;
            count++;
            // 插入新节点
            newNode->next = curr;
            prev->next = newNode;
        }
        p2 = p2->next;
    }
    newHead->val = count;
    return newHead;
}

void printList(node* head)
{
    node* p1 = head;
    for (int i = 0; i <= head->val; i++)
    {
        cout << p1->row << " " << p1->col << " " << p1->val;
        if (i != head->val)
        {
            cout << " " << endl;
        }
        p1 = p1->next;
    }
}

int main() {
    node* headA = NULL, *headB = NULL, *headC = NULL;
    int row, col;
    cin >> row >> col;
    headA = new node;
    headA->row = row;
    headA->col = col;
    cin >> headA->val;
    headA = createList(headA);
    headB = new node;
    headB->row = row;
    headB->col = col;
    cin >> headB->val;
    headB = createList(headB);
    headC = addLists(headA, headB);
    printList(headC);
    return 0;
}
