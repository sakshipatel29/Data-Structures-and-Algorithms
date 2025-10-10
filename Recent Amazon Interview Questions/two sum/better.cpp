//TC: O(NlogN) + O(N) AND O(N^2) in worst case for find operation.
//SC : O(N)
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            map<int, int> mpp;
            for(int i = 0 ; i < n; i++){
                int more = target - nums[i];
                if(mpp.find(more) != mpp.end()){
                    return {mpp[more], i};
                }
                mpp[nums[i]] = i;
            }
            return {-1,-1};
        }
    };