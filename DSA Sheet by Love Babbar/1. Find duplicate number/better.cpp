// TC: O(NlogN)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size() - 1;
            sort(nums.begin(), nums.end());
            for(int i = 1; i < nums.size(); i++){
                if(nums[i-1] == nums[i]) return nums[i];
            }
            return -1;
        }
    };