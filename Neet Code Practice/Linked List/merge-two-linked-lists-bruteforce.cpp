// TC: O(NlogN)
// SC: O(N)

#include <iostream>
#include <vector>
using namespace std;

// Logic: Use a vector to store the elements of the two linked lists
// Sort the vector
// Convert the vector to a linked list

class ListNode{
    public:
        int val;
        ListNode* next;
        ListNode(int val, ListNode* next) : val(val), next(next) {}
        ListNode(int val) : val(val), next(NULL) {}
    };
class Solution {
    public:
        ListNode* ConvertArrayToLL(vector<int>& nums){
            ListNode* head = new ListNode(nums[0], nullptr);
            ListNode* temp = head;
            for(int i = 1; i < nums.size(); i++){
                ListNode* newNode = new ListNode(nums[i], nullptr);
                temp->next = newNode;
                temp = temp->next;
            }
            return head;
        }
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == NULL) return list2;
            if(list2 == NULL) return list1;
            vector<int> nums;
            ListNode* temp1 = list1;
            ListNode* temp2 = list2;
            while(temp1 != NULL){
                nums.push_back(temp1->val);
                temp1 = temp1->next;
            }
            while(temp2 != NULL){
                nums.push_back(temp2->val);
                temp2 = temp2->next;
            }
            sort(nums.begin(), nums.end());
            return ConvertArrayToLL(nums);
        }
    };