// Time: O(n) → find middle + reverse + merge
// Space: O(1) → in-place, no extra structures

#include<iostream>
#include<vector>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int val) : val(val), next(NULL) {}
    };

class Solution {
    public:
        ListNode* reverseLL(ListNode* head){
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
        void reorderList(ListNode* head) {
            if (!head || !head->next) return;
            //1. find middle
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            //2. reverse second half
            ListNode* second = reverseLL(slow->next);
            slow->next = nullptr;
    
            //put 1 by 1 from first and second half
            ListNode* first = head;
            while(second){
                ListNode* temp1 = first->next;
                ListNode* temp2 = second->next;
    
                first->next = second;
                second->next = temp1;
    
                first = temp1;
                second = temp2;
            }
        }
    };