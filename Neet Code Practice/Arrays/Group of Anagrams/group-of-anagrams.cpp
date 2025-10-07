//TC: 0(N * NlogN) + O(N*N)
//SC: O(4 * N) N is strings in strs

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<string> sorted;
            vector<vector<string>> result;
            int n = strs.size();
            if (strs.size() == 1 && strs[0] == "")
                return {{""}};
            vector<int> vis(n, 0);
            for (int i = 0; i < strs.size(); i++) {
                string temp = strs[i];
                sort(temp.begin(), temp.end());
                sorted.push_back(temp);
            }
            for (int i = 0; i < n; i++) {
                vector<string> ans;
                if (!vis[i]) {
                    vis[i] = 1;
                    ans.push_back(strs[i]);
                    for (int j = i + 1; j < n; j++) {
                        if (sorted[j] == sorted[i] && !vis[j]) {
                            ans.push_back(strs[j]);
                            vis[j] = 1;
                        }
                    }
                }
                if (ans.size() != 0)
                    result.push_back(ans);
            }
            return result;
        }
    };