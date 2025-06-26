#include <iostream>
#include <string>

using namespace std;

struct node {
    int val;
    node* next;
};

node* createList() {
    string line;
    getline(cin, line);
    
    if (line.empty()) return NULL;
    
    node* head = NULL;
    node* tail = NULL;
    
    // 解析字符串，按 "->" 分割
    size_t pos = 0;
    while (pos < line.length()) {
        size_t arrow_pos = line.find("->", pos);
        
        string num_str;
        if (arrow_pos != string::npos) {
            num_str = line.substr(pos, arrow_pos - pos);
            pos = arrow_pos + 2; // 跳过 "->"
        } else {
            num_str = line.substr(pos);
            pos = line.length();
        }
        
        int value = stoi(num_str);
        
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

node* mergeList(node* l1, node* l2)
{
    node* head = nullptr;
    node* p1 = l1, *p2 = l2, *p3 = head;
    while (p1 != nullptr && p2 != nullptr)
    {
        node* newNode = new node;
        if (p1->val < p2->val)
        {
            newNode->val = p1->val;
            p1 = p1->next;
        }
        else
        {
            newNode->val = p2->val;
            p2 = p2->next;
        }
        if (head == nullptr)
        {
            head = newNode;
            p3 = newNode;  // p3 指向新的尾节点
        }
        else
        {
            p3->next = newNode;
            p3 = newNode;  // p3 指向新的尾节点
        }
        newNode->next = nullptr;  
    }
    if (p1 != nullptr)
    {
        p3->next = p1;
    }
    if (p2 != nullptr)
    {
        p3->next = p2;
    }
    return head;
}

void printList(node* head) {
    if (head == nullptr) {
        return;
    }
    
    node* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    head1 = createList();
    head2 = createList();
    node* newHead = mergeList(head1, head2);
    printList(newHead);
    return 0;
}
