// TC: O(2^N)
// SC: O(N)

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
    public:
        int func(int ind, int buy, int cap, vector<int> &prices, int n){
            if(ind == n || cap == 0) return 0;
            if(buy == 1){
                return max((-prices[ind] + func(ind+1, 0, cap, prices, n)),
                            (0 + func(ind+1, 1, cap, prices, n)));
            }
            return max((prices[ind] + func(ind+1, 1, cap-1, prices, n)),
                            (0 + func(ind+1, 0, cap, prices, n)));
        }
        int maxProfit(vector<int> &prices) {
            int n = prices.size();
            return func(0, 1, 2, prices, n);
        }
    };