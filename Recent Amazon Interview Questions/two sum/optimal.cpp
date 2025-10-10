//when asked to result bool
//TC: O(N) + O(NlogN)
//SC : O(N) because of sorting

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        string twoSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int left = 0;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] == target) return "YES";
                else{
                    if(nums[left] + nums[right] < target) left++;
                    else right--;
                }
            }
            return "NO";
        }
    };