// TC: O(2N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;
#include <climits>
#include <algorithm>

class Solution { 
    public: 
    pair<int, int> getMinMax(vector<int> arr) 
    { 
        int mini = *min_element(arr.begin(), arr.end()); 
        int maxi = *max_element(arr.begin(), arr.end()); 
        return {mini, maxi}; 
    } 
};