#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TC: O(n)
//SC: O(n) + O(n)

class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<int> trusts(n+1, 0);
            vector<int> trusted_by(n+1, 0);
            for(auto it : trust){
                trusts[it[0]]++;
                trusted_by[it[1]]++;
            }
            for(int i = 1; i <= n; i++){
                if(trusts[i] == 0 && trusted_by[i] == n-1){
                    return i;
                }
            }
            return -1;
        }
    };