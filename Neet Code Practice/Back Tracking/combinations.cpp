#include <iostream>
#include <vector>
using namespace std;

//TC: O(N*K)
//SC: O(K)

class Solution {
    public:
        void backtrack(int start, int n, int k, vector<vector<int>> &ans, vector<int> &ds){
            if(ds.size() == k){
                ans.push_back(ds);
                return;
            }
            //take
            for(int i = start; i <= n; i++){
                ds.push_back(i);
                backtrack(i+1, n, k, ans, ds);
                ds.pop_back();
            }
        }
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> ds;
            backtrack(1, n, k, ans, ds);
            return ans;
        }
    };