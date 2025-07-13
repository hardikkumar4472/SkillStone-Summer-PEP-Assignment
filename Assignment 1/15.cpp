#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* segregate012(ListNode* head) {
    vector<int> count(3, 0);
    ListNode* curr = head;
    
    while (curr != NULL) {
        count[curr->val]++;
        curr = curr->next;
    }
    
    curr = head;
    int i = 0;
    
    while (curr != NULL) {
        if (count[i] == 0) {
            i++;
        } else {
            curr->val = i;
            count[i]--;
            curr = curr->next;
        }
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
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(0);
    
    cout << "Original list: ";
    printList(head);
    
    ListNode* segregated = segregate012(head);
    
    cout << "After segregation: ";
    printList(segregated);
    
    return 0;
}