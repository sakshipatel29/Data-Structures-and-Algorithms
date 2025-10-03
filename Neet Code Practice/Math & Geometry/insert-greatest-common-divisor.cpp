#include <iostream>
// #include<bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;



class Solution {
    public:
        ListNode* insertGreatestCommonDivisors(ListNode* head) {
            ListNode* temp = head;
            if(head == NULL || head->next == NULL) return head;
            while(temp->next != NULL){
                int num = gcd(temp->val, temp->next->val);
                ListNode* node = new ListNode(num, nullptr);
                node->next = temp->next;
                temp->next = node;
                temp = temp->next->next;
            }
            return head;
        }
    };