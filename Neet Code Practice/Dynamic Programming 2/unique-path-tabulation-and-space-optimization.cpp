#include <iostream>
#include <vector>
using namespace std;

//TC: O(M*N)
//SC: O(N) + O(N)

class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, 0));
            vector<int> prev(n, 0);
            for(int i = 0; i < m; i++){
                vector<int> curr(n, 0);
                for(int j = 0; j < n; j++){
                    if(i == 0 && j == 0) {
                        curr[j] = 1;
                        continue;
                    }
                    int up = 0;
                    int left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1]; 
                    curr[j] = up + left;
                }
                prev = curr;
            }
            return prev[n-1];
        }
    };