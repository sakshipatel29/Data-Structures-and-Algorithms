#include <iostream>
#include <vector>
using namespace std;

//TC: O(N*2^N)
//SC: O(N*2^N)

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            int n = nums.size();
            int total = 1 << n;
            vector<vector<int>> ans;
            for(int i = 0; i < total; i++){
                vector<int> lst;
                for(int j = 0; j < n; j++){
                    if(i & (1 << j)){
                        lst.push_back(nums[j]);
                    }
                }
                ans.push_back(lst);
            }
            return ans;
        }
    };