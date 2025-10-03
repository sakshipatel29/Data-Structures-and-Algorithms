// TC: O(N)
// SC: O(N)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.size() != t.size()) return false;
            unordered_map<char, pair<int, int>> mpp;
            for(int i = 0;i < s.size(); i++){
                mpp[s[i]].first++;
                mpp[t[i]].second++;
            }
            for(auto it : mpp){
                if(it.second.first != it.second.second) return false;
            }
            return true;
        }
    };