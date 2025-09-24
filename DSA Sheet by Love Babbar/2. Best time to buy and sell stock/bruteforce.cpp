// TC: O(N^2)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = INT_MIN;
            for(int i = 0; i < prices.size();i++){
                for(int j = i + 1; j < prices.size(); j++){
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
                }
            }
            if (maxProfit > 0) return maxProfit;
            return 0;
        }
    };