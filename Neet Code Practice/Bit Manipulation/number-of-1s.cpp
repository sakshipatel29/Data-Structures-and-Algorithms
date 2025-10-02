#include <iostream>
using namespace std;

//TC: O(logN)
//SC: O(1)

class Solution {
    public:
        int hammingWeight(int n) {
            int res = 0;
            while(n){
                n = n & (n-1);
                res++;
            }
            return res;
        }
    };