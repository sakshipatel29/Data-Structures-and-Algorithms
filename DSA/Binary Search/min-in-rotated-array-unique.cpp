
//TC: O(logn)
//SC: O(1)



#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;
int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }else if(nums[mid] < nums[high]){
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << findMin(nums) << endl;
    return 0;
}