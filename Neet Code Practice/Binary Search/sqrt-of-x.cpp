// TC: O(logn)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            if(x == 0 || x == 1) return x;
            int left = 1;
            int right = x/2;
            while(left <= right){
                int mid = left + (right - left)/2;
                if((long)mid * mid == (long)x) return mid;
                else if((long)mid * mid > (long) x){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            return right;
        }
    };