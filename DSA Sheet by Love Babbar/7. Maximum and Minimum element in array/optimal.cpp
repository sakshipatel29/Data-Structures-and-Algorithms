// TC: O(N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;
#include <climits>
#include <algorithm>

class Solution {
    public:
        pair<int, int> getMinMax(vector<int> arr) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int i = 0; i < arr.size(); i++){
                mini = min(mini, arr[i]);
                maxi = max(maxi, arr[i]);
            }
            return {mini, maxi};
        }
    };