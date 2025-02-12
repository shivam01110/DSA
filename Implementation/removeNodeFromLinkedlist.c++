#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}  // constructor hy

};
// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// Function to remove nodes with greater values to the right
ListNode* removeNodes(ListNode* head) {
    // Step 1: Reverse the linked list
    head = reverseList(head);

	// reverse ka function bna le ab phle aur bolte reh kuch kuch 
// upar likha hai reverse ka function
    
    // Step 2: Traverse the reversed list and remove nodes
    ListNode* curr = head;
    int maxVal = INT_MIN;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        if (curr->val >= maxVal) {
            // Keep this node and update maxVal
            maxVal = curr->val;
            prev = curr;
            curr = curr->next;
        } else {
            // Remove the node
            prev->next = curr->next;
            curr = prev->next;
        }
    }
    
    // Step 3: Reverse the list again to restore the original order
    head = reverseList(head);
    
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 11 -> 15 -> 2 -> 3 -> 9 -> 8 -> 7 -> 6
    ListNode* head = new ListNode(11);
    head->next = new ListNode(15);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(6);

    // Printing the original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Removing nodes greater than any node to their right
    head = removeNodes(head);

    // Printing the modified linked list
    cout << "Modified Linked List: ";
    printList(head);

    return 0;
}
//output ykya tha