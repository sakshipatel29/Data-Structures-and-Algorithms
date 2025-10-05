// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> mpp;
            for(int i=0; i<nums.size();i++){
                int left = target - nums[i];
                if(mpp.find(left) != mpp.end()) return {mpp[target-nums[i]], i};
                mpp[nums[i]] = i;  
            }
            return {-1,-1};
        }
    };