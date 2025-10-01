#include<iostream>
#include<vector>
using namespace std;
// Time Complexity: O(logn)
// Space Complexity: O(1)
// Guessing Number
// Logic: Use binary search to find the number

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num){
    return 0;
}
 class Solution {
    public:
        int guessNumber(int n) {
            if(n == 1) return n;
            int left = 1;
            int right = n;
            while(left <= right){
                int mid = left + (right - left)/2;
                if(guess(mid) == 1){
                    left = mid + 1;
                }else if(guess(mid) == -1){
                    right = mid;
                }else{
                    return mid;
                }
            }
            return -1;
        }
    };