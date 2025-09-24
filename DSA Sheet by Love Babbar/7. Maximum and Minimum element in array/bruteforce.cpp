// TC: O(NlogN)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        pair<int, int> getMinMax(vector<int> arr) {
            sort(arr.begin(), arr.end());
            return {arr[0], arr[arr.size()-1]};
        }
    };