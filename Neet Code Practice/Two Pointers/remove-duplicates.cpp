//TC: O(N)
//SC: O(1)


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 0;
            for(int j = 1; j < nums.size(); j++){
                if(nums[i] != nums[j]){
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i + 1;
        }
    };