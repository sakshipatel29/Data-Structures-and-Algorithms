// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isPallinNum(int n){
            vector<int> pal;
            while(n > 9){
                int temp = n % 10;
                n = n/10;
                pal.push_back(temp);
            }
            pal.push_back(n);
            int left = 0;
            int right = pal.size() - 1;
            while(left <= right){
                if(pal[left] == pal[right]){
                    left++;
                    right--;
                }else{
                    return false;
                }
            }
            return true;
        }
        bool isPalinArray(vector<int> &arr) {
            for(int i = 0; i < arr.size(); i++){
                if(!isPallinNum(arr[i])) return false;
            }
            return true;
        }
    };