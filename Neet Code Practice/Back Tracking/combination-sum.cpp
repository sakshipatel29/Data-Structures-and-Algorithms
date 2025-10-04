//TC : 2^t * k
//SC : k * x(x  is possible combinations) 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void recursion(int ind, int target, vector<int>& candidates,
                        vector<vector<int>>& ans, vector<int>& ds) {
            int n = candidates.size();
            if (ind == n) {
                if (target == 0) {
                    ans.push_back(ds);
                }
                return;
            }
            if (candidates[ind] <= target) {
                ds.push_back(candidates[ind]);
                recursion(ind, target - candidates[ind], candidates, ans, ds);
                ds.pop_back();
            }
            recursion(ind + 1, target, candidates, ans, ds);
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            recursion(0, target, candidates, ans, ds);
            return ans;
        }
    };