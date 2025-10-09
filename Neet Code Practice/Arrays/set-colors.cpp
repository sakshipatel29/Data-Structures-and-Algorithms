//TC: O(N)
//SC: O(1)


#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            int mid = 0;
            while(mid <= right){
                if(nums[mid] == 0){
                    swap(nums[left], nums[mid]);
                    left++;
                    mid++;
                }else if(nums[mid] == 2){
                    swap(nums[mid], nums[right]);
                    right--;
                }else{
                    mid++;
                }
            }
        }
    };