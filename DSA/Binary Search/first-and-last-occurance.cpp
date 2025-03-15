// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

// Time Complexity: 2 * O(log n)
// Space Complexity: O(1)
#include <vector>
using namespace std;
class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lowerbound = lowerBound(nums, target);
        if(lowerbound == n || nums[lowerbound] != target){
            return {-1, -1};
        }
        return {lowerbound, upperBound(nums, target) -1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);
    return 0;
}