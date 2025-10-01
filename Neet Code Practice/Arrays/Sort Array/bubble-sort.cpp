#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Bubble Sort

// Logic: Put the largest element to the last by swapping

class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i <= n-2; i++){
                for(int j = 0; j < n - 1 - i; j++){
                    if(nums[j] > nums[j+1]){
                        swap(nums[j], nums[j+1]);
                    }
                }
            }
            return nums;
        }
    };


//O(N) for the best case. when we use didswap flag to check if the array is already sorted. 