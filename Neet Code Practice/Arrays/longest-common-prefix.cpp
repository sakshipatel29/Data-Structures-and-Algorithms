//TC: O(N X M) N is size of array
//SC: O(M) M is length of first string in array.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";
            if(strs.size() == 1) return strs[0];
            int n = strs[0].size();
            for(int i = 0; i < n; i++){
                int j = 1;
                int k = j;
                while(j < strs.size()){
                    if(strs[j][i] == strs[j-1][i]) j++;
                    else break;
                }
                if(j == strs.size()){
                    ans += strs[k][i];
                }else{
                    break;
                }
            }
            return ans;
        }
    };