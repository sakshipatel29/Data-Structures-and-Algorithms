#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int maxi = nums[0];
            int sum = nums[0];
            int mini = nums[0];
            int minSum = nums[0];
            int total = nums[0];
            int n = nums.size();
    
            for(int i = 1; i < n; i++){
                maxi = max(maxi + nums[i], nums[i]);
                sum = max(sum, maxi);
    
                mini = min(nums[i], mini + nums[i]);
                minSum = min(minSum, mini);
    
                total += nums[i];
            }
            if(minSum == total) return sum;
            return max(sum, total- minSum);
        }
    };