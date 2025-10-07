//TC: O(n × k log k)
//SC:O(n × k)

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> result;
            unordered_map<string, vector<string>> mpp;
    
            for (auto &s : strs) {
                string t = s;
                sort(t.begin(), t.end());
                mpp[t].push_back(s);
            }
            for(auto &it : mpp){
                result.push_back(it.second);
            }
            return result;
        }
    };