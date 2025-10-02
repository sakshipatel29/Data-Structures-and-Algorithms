// TC: O(N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxi = INT_MIN;
            int mini = prices[0];
            for(int i = 1; i < prices.size(); i++){
                int cost = prices[i] - mini;
                maxi = max(maxi, cost);
                mini = min(mini, prices[i]);
            }
            if(maxi > 0) return maxi;
            return 0;
        }
    };