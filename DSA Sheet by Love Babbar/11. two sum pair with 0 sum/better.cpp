// TC: O(NlogN)
// SC: O(N)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> getPairs(vector<int>& arr) {
            unordered_map<int, int> mpp;
            for (int num : arr) {
                mpp[num]++;
            }
            
            vector<int> temp;
            for(auto &p: mpp){
                int num = p.first;
                int cnt = p.second;
                if (num == 0) {
                    if (cnt >= 2) temp.push_back(0);
                } else if (num > 0) {
                    if (mpp.find(-num) != mpp.end()) temp.push_back(num);
                }
            }
            sort(temp.begin(), temp.end());
            temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
            vector<vector<int>> ans;
            for (int i = (int)temp.size() - 1; i >= 0; --i)
                ans.push_back({-temp[i], temp[i]});
    
            return ans;
        }
    };