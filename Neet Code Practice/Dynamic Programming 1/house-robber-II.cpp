#include <iostream>
#include <vector>
using namespace std;

// Recursion:

//TC: O(2^N)
//SC: O(n)

class Solution {
    public:
        int func(int n, vector<int>& nums){
            if(n == 0) return nums[n];
            if(n < 0) return 0;
            int take = nums[n] + func(n-2, nums);
            int notTake = 0 + func(n-1, nums);
            return max(take, notTake);
        }
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> temp1;
            vector<int> temp2;
            for(int i = 0; i < n; i++){
                if(i != 0) temp1.push_back(nums[i]);
                if(i != n-1) temp1.push_back(nums[i]);
            }
            int m = temp1.size();
            return max(func(m-1,temp1), func(m-1,temp2));
        }
    };

//Memoization:

//TC: O(N)
//SC: O(n)

class Solution {
    public:
        int func(int n, vector<int>& nums, vector<int>& dp){
            if(n == 0) return nums[n];
            if(n < 0) return 0;
            if(dp[n]!= -1) return dp[n];
            int take = nums[n] + func(n-2, nums, dp);
            int notTake = 0 + func(n-1,nums , dp);
            return dp[n] = max(take, notTake);
        }
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> temp1;
            vector<int> temp2;
    
            for(int i = 0; i < n; i++){
                if(i != 0) temp1.push_back(nums[i]);
                if(i != n-1) temp2.push_back(nums[i]);
            }
            int m = temp1.size();
            vector<int> dp(m, -1);
            vector<int> dp1(m, -1);
    
            return max(func(m-1,temp1, dp), func(m-1,temp2, dp1));
        }
    };

//Tabulation:

//TC: O(N)
//SC: O(n)

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> temp1;
            vector<int> temp2;
    
            for(int i = 0; i < n; i++){
                if(i != 0) temp1.push_back(nums[i]);
                if(i != n-1) temp2.push_back(nums[i]);
            }
            int m = temp1.size();
            vector<int> dp(m, -1);
            vector<int> dp1(m, -1);
    
            for(int i = 0; i < m; i++){
                if(i == 0){
                    dp[i] = temp1[i];
                    dp1[i] = temp2[i];
                }
                else if(i == 1){
                    dp[i] = max(temp1[i], temp1[i-1]);
                    dp1[i] = max(temp2[i], temp2[i-1]);
                }else {
                    dp[i] = max(temp1[i] + dp[i-2], 0 + dp[i-1]);
                    dp1[i] = max(temp2[i] + dp1[i-2], 0 + dp1[i-1]);
                }
            }
            return max(dp[m-1], dp1[m-1]);
        }
    };

//Space Optimization:

//TC: O(N)
//SC: O(1)

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            vector<int> temp1;
            vector<int> temp2;
    
            for(int i = 0; i < n; i++){
                if(i != 0) temp1.push_back(nums[i]);
                if(i != n-1) temp2.push_back(nums[i]);
            }
    
            int m = temp1.size();
            if (m == 1) 
                return max(temp1[0], temp2[0]);
    
            int prev2 = temp1[0];
            int prev = max(temp1[0], temp1[1]);
            int prev12 = temp2[0];
            int prev1 = max(temp2[0], temp2[1]);
    
            for(int i = 2; i < m; i++){
                int curr = max(temp1[i] + prev2, 0 + prev);
                int curr1 = max(temp2[i] + prev12, 0 + prev1);
                prev2 = prev;
                prev = curr;
                prev12 = prev1;
                prev1 = curr1;
            }
            return max(prev, prev1);
        }
    };