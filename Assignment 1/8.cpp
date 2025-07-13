#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }
    
    ListNode* curr = head;
    int len = 1;
    while (curr->next != NULL) {
        curr = curr->next;
        len++;
    }
    
    curr->next = head;
    k = k % len;
    
    for (int i = 0; i < len - k; i++) {
        curr = curr->next;
    }
    
    head = curr->next;
    curr->next = NULL;
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
    ListNode* rotated = rotateRight(head, k);
    
    cout << "After rotation: ";
    printList(rotated);
    
    return 0;
}