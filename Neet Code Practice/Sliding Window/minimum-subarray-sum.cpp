#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int left = 0;
            int right = 0;
            int sum = 0;
            int mini =INT_MAX;
            while(right <  nums.size() && left <= right){
                sum += nums[right];
                while(target <= sum && left < nums.size()){
                    mini = min((right - left + 1), mini);
                    sum -= nums[left];
                    left++;
                }
                right++;
            }
            if(mini == INT_MAX) return 0;
            return mini;
        }
    };