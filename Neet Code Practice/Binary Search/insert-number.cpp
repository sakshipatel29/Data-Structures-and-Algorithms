#include<iostream>
#include<vector>
using namespace std;
// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            int mid = 0;
            int ans = nums.size();
            while(left <= right){
                mid = left + (right - left)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] > target){
                    ans = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            return ans;
        }
    };