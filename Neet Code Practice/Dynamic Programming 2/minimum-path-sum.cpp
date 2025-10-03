// Recursion:
// TC: 2^(N*M)
// SC: (N*M)

// Memoization:
// TC: (N*M) 
// SC: (N*M) + Recursion stack space

// Tabulation:
// TC: (N*M)
// SC: (N*M)

// Space Optimization:
// TC: O(N*M)
// SC: O(M)



#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int recursion(int i, int j, vector<vector<int>>& grid,
                        vector<vector<int>>& dp) {
            if (i == 0 && j == 0)
                return grid[i][j];
            if (i < 0 || j < 0)
                return 1e9;
            if (dp[i][j] != -1)
                return dp[i][j];
            int up = grid[i][j] + recursion(i - 1, j, grid, dp);
            int left = grid[i][j] + recursion(i, j - 1, grid, dp);
            return dp[i][j] = min(up, left);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            vector<int> prev(m + 1, 0), curr(m + 1, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 && j == 0) {
                        curr[j] = grid[i][j];
                        continue;
                    } else {
                        int up = grid[i][j];
                        int left = grid[i][j];
                        if (i > 0) {
                            up += prev[j];
                        } else {
                            up += 1e9;
                        }
                        if (j > 0) {
                            left += curr[j - 1];
                        } else {
                            left += 1e9;
                        }
                        curr[j] = min(up, left);
                    }
                }
                prev = curr;
            }
            return prev[m - 1];
        }
    };