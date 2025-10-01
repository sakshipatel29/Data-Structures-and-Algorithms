#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Reverse Linked List

// Logic: Use recursion to reverse the linked list

// Recursive Solution

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val) : val(val), next(NULL) {}
};


class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head == NULL || head->next == NULL) return head;
            ListNode* temp = head;
            ListNode* newHead = reverseList(head->next);
            ListNode* front = temp->next;
            front->next = temp;
            temp->next = NULL;
            return newHead;
        }
    };


// Iterative Solution

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if(head == NULL || head->next == NULL) return head;
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp != NULL){
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }
            return prev;
        }
    };