// TC: O(N) // fast pointer moves from 1st to last
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val, ListNode* next) : val(val), next(next) {}
        ListNode(int val) : val(val), next(NULL) {}
    };

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* fast = head;
            ListNode* slow = head;
            for(int i = 0; i < n; i++){
                fast = fast->next;
                if(fast == NULL){
                    ListNode* newHead = head->next;
                    delete head;
                    return newHead;
                }
            }
            while(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            ListNode* delNode = slow->next;
            slow->next = slow->next->next;
            delete delNode;
            return head;
        }
    };