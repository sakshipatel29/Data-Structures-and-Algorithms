//TC: O(NlogN)
//SC: O(N)

#include<iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> pq;
            for (int i = 0; i < nums.size(); i++) {
                pq.push(nums[i]);
            }
            while (k > 1) {
                pq.pop();
                k--;
            }
            return pq.top();
        }
    };
