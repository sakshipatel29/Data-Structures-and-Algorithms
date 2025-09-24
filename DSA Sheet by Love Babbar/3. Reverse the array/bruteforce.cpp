// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void reverseArray(vector<int> &arr) {
            int n = arr.size();
            vector<int> temp(n);
            for(int i = 0; i< n; i++){
                temp[i] = arr[n - 1 - i];
            }
            for(int i = 0; i< n; i++){
                arr[i] = temp[i];
            }
        }
    };