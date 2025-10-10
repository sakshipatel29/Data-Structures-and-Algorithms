// TC: O(2N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k = k % n; // because k can be bigger than n
            reverse(nums.begin(), nums.end());  
            int left = 0;
            int right = k-1;
            while(left < right){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
            left = k;
            right = nums.size() - 1;
            while(left <= right){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
    };