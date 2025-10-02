// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Logic: Use a map to store the elements and check if the element is already in the map    

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_map<int, int> mpp;
            for(int i = 0; i < nums.size(); i++){
                if(mpp[nums[i]] >= 1) return true;
                else mpp[nums[i]] = 1;
            }
        }
    };