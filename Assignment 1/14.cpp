#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    if (fast != NULL) {
        slow = slow->next;
    }
    
    while (prev != NULL && slow != NULL) {
        if (prev->val != slow->val) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }
    
    return true;
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
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    
    cout << "List: ";
    printList(head);
    
    if (isPalindrome(head)) {
        cout << "The list is a palindrome" << endl;
    } else {
        cout << "The list is not a palindrome" << endl;
    }
    
    return 0;
}