// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;        

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n - 1;
        int low = 1;
        int high = n - 2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
            }else if(nums[mid] > nums[mid - 1]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}