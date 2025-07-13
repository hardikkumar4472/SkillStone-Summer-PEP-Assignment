#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNodes(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    head->next = removeNodes(head->next);
    
    if (head->next != NULL && head->val < head->next->val) {
        return head->next;
    } else {
        return head;
    }
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* modified = removeNodes(head);
    
    cout << "Modified list: ";
    printList(modified);
    
    return 0;
}