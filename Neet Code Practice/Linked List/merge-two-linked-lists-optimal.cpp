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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == NULL) return list2;
            if(list2 == NULL) return list1;
            ListNode* t1 = list1;
            ListNode* t2 = list2;
            ListNode* dummy = new ListNode(-1, nullptr);
            ListNode* temp = dummy;
            while(t1 != NULL && t2 != NULL){
                if(t1->val <= t2->val){
                    temp->next = t1;
                    temp = temp->next;
                    t1 = t1->next;
                }else{
                    temp->next = t2;
                    temp = temp->next;
                    t2 = t2->next;
                }
            }
            while(t1 != NULL){
                temp->next = t1;
                temp = temp->next;
                t1 = t1->next;
            }
            while(t2 != NULL){
                temp->next = t2;
                temp = temp->next;
                t2 = t2->next;
            }
            return dummy->next;
        }
    };