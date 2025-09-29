// TC: O(N^2)
// SC: O(N)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> getPairs(vector<int>& arr) {
            set<vector<int>> st;
            for(int i = 0; i < arr.size(); i++){
                for(int j = i + 1; j < arr.size(); j++){
                    if(arr[i] + arr[j] == 0){
                        int a = min(arr[i], arr[j]);
                        int b = max(arr[i], arr[j]);
                        st.insert({a,b});
                    }
                }
            }
            vector<vector<int>> ans(st.begin(), st.end());
            return ans;
        }
    };