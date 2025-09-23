// TC: O(N^2)
// SC: O(1)


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int n = nums.size() - 1;
            for(int i = 0; i < nums.size(); i++){
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[i] == nums[j]) return nums[i];
                }
            }
            return -1;
        }
    };