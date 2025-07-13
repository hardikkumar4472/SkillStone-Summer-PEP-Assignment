#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;
    
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
    
    if (count == k) {
        curr = reverseKGroup(curr, k);
        
        while (count-- > 0) {
            ListNode* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
        }
        head = curr;
    }
    
    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original list: ";
    printList(head);
    
    int k = 2;
    ListNode* reversed = reverseKGroup(head, k);
    
    cout << "After reversing in groups of " << k << ": ";
    printList(reversed);
    
    return 0;
}