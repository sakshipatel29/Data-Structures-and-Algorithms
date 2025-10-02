// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
using namespace std;

// Logic: Use a recursive function to find the minimum cost to climb the stairs

class Solution {
    public:
        int recursion(int ind, vector<int>& cost, vector<int>& dp){
            if(ind < 0) return 0;
            if(ind == 0 || ind == 1) return cost[ind];
            if(dp[ind] != -1) return dp[ind];
            int take = recursion(ind - 1, cost, dp) + cost[ind];
            int notTake = 0;
            if(ind > 1) notTake = recursion(ind - 2, cost, dp) + cost[ind];
            return dp[ind] = min(take, notTake);
        }
        int minCostClimbingStairs(vector<int>& cost) {
            int n = cost.size();
            int prev2 = cost[0];
            int prev1 = cost[1];
            for(int i = 2; i < n;i++){
                int take = prev1 + cost[i];
                int notTake = 0;
                notTake = prev2 + cost[i];
                int curr = min(take, notTake);
    
                prev2 = prev1;
                prev1 = curr;
            }
            return min(prev1, prev2);
        }
    };