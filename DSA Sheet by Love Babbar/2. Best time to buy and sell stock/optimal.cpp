// TC: O(N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = INT_MIN;;
            int mini = prices[0];
    
            for(int i = 1; i < prices.size();i++){
                int cost = prices[i] - mini;
                profit = max(profit, cost);
                mini = min(mini, prices[i]);
            }
            if (profit > 0) return profit;
            return 0;
        }
    };