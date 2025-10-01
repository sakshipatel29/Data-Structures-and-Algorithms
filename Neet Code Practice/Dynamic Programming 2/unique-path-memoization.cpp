#include <iostream>
#include <vector>
using namespace std;

//TC: O(M*N)
//SC: O(M*N)

class Solution {
    public:
        int recursion(int m, int n, vector<vector<int>> &dp){
            if(n == 0 && m == 0) return 1;
            if(m < 0 || n < 0) return 0;
            if(dp[m][n] != -1) return dp[m][n];
    
            int left = recursion(m, n-1, dp);
            int right = recursion(m-1, n, dp);
            return dp[m][n] = left + right;
        }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return recursion(m-1,n-1, dp);
        }
    };