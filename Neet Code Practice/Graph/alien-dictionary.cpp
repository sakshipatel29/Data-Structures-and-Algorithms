// Alien Dictionary
// TC: O(N*M)
// SC: O(1)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isAlienSorted(vector<string>& words, string order) {
            unordered_map<char, int> mpp;
            for(int i = 0; i < order.size(); i++){
                mpp[order[i]] = i;
            }
            for(int i = 1; i < words.size(); i++){
                string w1 = words[i-1];
                string w2 = words[i];
                int j = 0;
    
                while(j < w1.size() && j < w2.size()){
                    if(mpp[w1[j]] < mpp[w2[j]]) break;
                    if(mpp[w1[j]] > mpp[w2[j]]) return false;
                    j++;
                }
                if(j == w2.size() && w1.size() > w2.size()) return false;
            }
            return true;
        }
    };