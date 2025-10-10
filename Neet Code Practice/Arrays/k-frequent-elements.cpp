// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mpp; 
            for(auto &i : nums){
                mpp[i]++;
            }
            vector<vector<int>> buckets(nums.size() + 1);
            for(auto& [it, num] : mpp){
                buckets[num].push_back(it);
            }
            vector<int> ans;
            for(int i = nums.size(); i >= 0 && ans.size() < k; i--){
                for(auto num : buckets[i]){
                    ans.push_back(num);
                    if(ans.size() == k) break;
                }
            }
            return ans;
        }
    };