#include <iostream>
#include <vector>
using namespace std;

//TC: O(N)
//SC: O(N)

class Solution {
    public:
        int recursion(int ind, vector<int>& nums, vector<int> &dp){
            if(ind == 0) return nums[ind];
            if(ind < 0) return 0;
            if(dp[ind] != -1) return dp[ind];
            int take = nums[ind] + recursion(ind - 2, nums, dp);
            int notTake = 0 + recursion(ind - 1, nums, dp);
            return dp[ind] = max(take, notTake);
        }
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
    
            vector<int> dp(n, -1);
            // dp[0] = nums[0];
            // dp[1] = max(nums[0], nums[1]);
    
            // for(int i = 2; i < n; i++){
            //     dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
            // }
            return recursion(n-1, nums, dp);
            // return dp[n-1];
        }
    };