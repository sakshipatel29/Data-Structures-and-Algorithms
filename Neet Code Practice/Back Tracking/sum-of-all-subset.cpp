#include <iostream>
#include <vector>
using namespace std;

//TC: O(N)
//SC: O(1)

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int OR_total = 0;
            for (int num : nums) OR_total |= num;  // OR of all numbers
            return OR_total << (nums.size() - 1);  // multiply by 2^(n-1)
        }
    };