#include <iostream>
#include <vector>
using namespace std;

//TC: O(M*N)
//SC: O(M*N)

class Solution {
    public:
        int recursion(int i, int j, vector<vector<int>>& obstacleGrid,
                      vector<vector<int>>& dp) {
            if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
                return 0;
            if (i == 0 && j == 0)
                return 1;
            if (dp[i][j] != -1)
                return dp[i][j];
            int up = 0;
            int left = 0;
            if (i > 0)
                up = recursion(i - 1, j, obstacleGrid, dp);
            if (j > 0)
                left = recursion(i, j - 1, obstacleGrid, dp);
            return dp[i][j] = up + left;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> dp(m, vector<int>(n, 0));
            vector<int> prev(n, 0);
            for (int i = 0; i < m; i++) {
                vector<int> curr(n, 0);
                for (int j = 0; j < n; j++) {
                    if (obstacleGrid[i][j] == 1)
                        curr[j] = 0;
                    else if (i == 0 && j == 0)
                        curr[j] = 1;
                    else {
                        int up = 0;
                        int left = 0;
                        if (i > 0)
                            up = prev[j];
                        if (j > 0)
                            left = curr[j - 1];
                        curr[j] = up + left;
                    }
                }
                prev = curr;
            }
            return prev[n - 1];
        }
    };