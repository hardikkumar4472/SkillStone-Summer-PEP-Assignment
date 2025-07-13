#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    
    return dummy.next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* num1 = new ListNode(2);
    num1->next = new ListNode(4);
    num1->next->next = new ListNode(3);
    
    ListNode* num2 = new ListNode(5);
    num2->next = new ListNode(6);
    num2->next->next = new ListNode(4);
    
    cout << "Number 1: ";
    printList(num1);
    cout << "Number 2: ";
    printList(num2);
    
    ListNode* sum = addTwoNumbers(num1, num2);
    
    cout << "Sum: ";
    printList(sum);
    
    return 0;
}