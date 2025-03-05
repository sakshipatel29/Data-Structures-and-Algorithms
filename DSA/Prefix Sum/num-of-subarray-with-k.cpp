//TC: O(N)
//SC: O(N)
    
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n, 0);
        preSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            preSum[i] = preSum[i - 1] + nums[i];
        }
        unordered_map<int, int> mpp;
        int count = 0;
        for(int j = 0; j < n; j++){
            if(preSum[j] == k){
                count++;
            }
            int val = preSum[j] - k;
            if(mpp.find(val) != mpp.end()){
                count += mpp[val];
            }

            if(mpp.find(preSum[j]) == mpp.end()){
                mpp[preSum[j]] = 0;
            }
            mpp[preSum[j]]++;
        }
        return count;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    cout << obj.subarraySum(nums, k) << endl;
    return 0;
}   