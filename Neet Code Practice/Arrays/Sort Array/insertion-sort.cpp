#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Insertion Sort

// Logic: Insert the element in the correct position

// It is better than bubble sort because it is adaptive.

class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i < n; i++){
                int j = i;
                while(j > 0 && nums[j-1] > nums[j]){
                    swap(nums[j-1], nums[j]);
                    j--;
                }
            }
            return nums;
        }
    };