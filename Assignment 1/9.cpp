#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    Node* newHead = head->next;
    curr = head;
    while (curr != NULL) {
        Node* temp = curr->next;
        curr->next = temp->next;
        if (temp->next != NULL) {
            temp->next = temp->next->next;
        }
        curr = curr->next;
    }
    
    return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << "[" << head->val << ",";
        if (head->random) {
            cout << head->random->val;
        } else {
            cout << "null";
        }
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    
    head->random = NULL;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    
    cout << "Original list: ";
    printList(head);
    
    Node* copied = copyRandomList(head);
    
    cout << "Copied list: ";
    printList(copied);
    
    return 0;
}