// TC: O(N)
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
        bool hasCycle(ListNode *head) {
            if(head == NULL || head->next == NULL) return false;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) return true;
            }
            return false;
        }
    };