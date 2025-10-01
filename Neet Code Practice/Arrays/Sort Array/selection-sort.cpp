#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Insertion Sort

// Logic: Insert the element in the correct position

class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i <= n-2; i++){
                int mini = i;
                for(int j = i; j <= n-1; j++){
                    if(nums[j] < nums[mini]) mini = j;
                }
                swap(nums[i], nums[mini]);
            }
            return nums;
        }
    };