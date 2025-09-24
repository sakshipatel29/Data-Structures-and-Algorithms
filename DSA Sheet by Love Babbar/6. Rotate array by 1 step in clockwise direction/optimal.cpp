// TC: O(N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int> &arr) {
            reverse(arr.begin(), arr.end());
            reverse(arr.begin() + 1, arr.end());
        }
    };