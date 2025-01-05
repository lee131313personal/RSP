#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

// Definition for singly-linked list.
// Assume the number does not contains any leading zero

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode finalHead(0); // Create a final head node.
        ListNode* current = &finalHead; // Current node for iteration, starts at final head.
        int carry = 0; // Initialize carry to 0.

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1_val = 0; // Default value for l1 is 0.
            int l2_val = 0; // Default value for l2 is 0.

            // If l1 is not exhausted, use its value.
            if (l1 != nullptr) {
                l1_val = l1->val;
                l1 = l1->next; // Move to the next node in l1.
            }

            // If l2 is not exhausted, use its value.
            if (l2 != nullptr) {
                l2_val = l2->val;
                l2 = l2->next; // Move to the next node in l2.
            }

            int sum = l1_val + l2_val + carry; // Add the two values and the carry.
            carry = sum / 10; // Calculate the new carry.

            // Create a new node with the digit part of the sum and attach it to the current node.
            current->next = new ListNode(sum % 10);
            current = current->next; // Move the current pointer to the new node.
        }

        return finalHead.next; // Return the head of the new list, which is next of the final node.
    }
};
