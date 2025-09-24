// TC: O(N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isPallinNum(int n){
            if(n < 10) return true;
            int original = n;
            int rev = 0;
            while(n > 9){
                n = n/10;
                rev = rev*10 + n%10;
            }
            rev = rev*10 + n;
            return original == rev;
        }
        bool isPalinArray(vector<int> &arr) {
            for(int i = 0; i < arr.size(); i++){
                if(!isPallinNum(arr[i])) return false;
            }
            return true;
        }
    };