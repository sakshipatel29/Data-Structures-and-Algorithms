#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TC: O(NlogN)
//SC: O(N)

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>> ans;
            if(intervals.size() == 0) return ans;
            sort(intervals.begin(), intervals.end());
            vector<int> curr = intervals[0];
            for(int i = 1; i < intervals.size(); i++){
                if(intervals[i][0] <= curr[1]){
                    curr[1] = max(curr[1], intervals[i][1]);
                }else{
                    ans.push_back(curr);
                    curr = intervals[i];
                }
            }
            ans.push_back(curr);
            return ans;
        }
    };