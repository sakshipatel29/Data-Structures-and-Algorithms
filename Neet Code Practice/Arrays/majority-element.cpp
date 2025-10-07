//Boyer-Moore Voting Algorithm.
//TC: O(N)
//SC: O(1)
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int candidate;
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(count == 0) {
                    candidate = nums[i];
                    count = 1;
                }  
                else if(candidate == nums[i]) count++;
                else count--;
            }
            return candidate;
        }
    };