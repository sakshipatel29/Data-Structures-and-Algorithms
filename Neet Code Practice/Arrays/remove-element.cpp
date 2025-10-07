//TC: O(N)
//SC: O(1)


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int i = 0;
            while(i < nums.size()){
                if(nums[i] == val){
                    nums.erase(nums.begin() + i);
                }else{
                    i++;
                }
            }
            return i;
        }
    };