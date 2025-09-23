// TC: O(NlogN)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            int ans = -1;
            while(left <= right){
                int mid = left + (right - left)/2;
                int count = 0;
                for(int x : nums){
                    if(x <= mid) count++;
                }
    
                if(count > mid){
                    ans = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                } 
            }
            return ans;
        }
    };