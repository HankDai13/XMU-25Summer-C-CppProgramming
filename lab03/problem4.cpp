#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
};
ListNode* createList()
{
    ListNode* head = NULL;
    ListNode* p1, * p2;
    p1 = new ListNode;
    p2 = p1;
    cin >> p1->val;
    while (p1->val != -1)
    {
        if (head == NULL)
            head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 = new struct ListNode;
        cin >> p1->val;
    }
    p2->next = NULL;
    delete p1;
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 反转两个链表
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    ListNode* result = nullptr;
    int carry = 0;
    
    // 从个位开始相加
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        // 头插法构建结果链表
        ListNode* newNode = new ListNode;
        newNode->val = sum % 10;
        newNode->next = result;
        result = newNode;
    }
    
    return result;
}

int main() {
    ListNode* head1,*head2;
    head1 = createList();
    head2 = createList();
    ListNode* ans = addTwoNumbers(head1, head2);
    if (ans == NULL)
        cout << "-1";
    else {
        while (ans != NULL) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout<<-1;
    }
    return 0;
}
