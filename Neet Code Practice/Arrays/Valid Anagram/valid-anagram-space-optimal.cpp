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
            unordered_map<char, int> mpp;
            for(int i = 0;i < s.size(); i++){
                mpp[s[i]]++;
            }
            for(auto ch : t){
                if(mpp[ch] != 0) mpp[ch]--;
                else return false;
            }
            return true;
        }
    };