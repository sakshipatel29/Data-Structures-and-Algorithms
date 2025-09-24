// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void rotate(vector<int> &arr) {
            int n = arr.size();
            vector<int> temp;
            temp.push_back(arr[n-1]);
            for(int i = 0; i < arr.size()-1;i++){
                temp.push_back(arr[i]);
            }
            arr = temp;
        }
    };