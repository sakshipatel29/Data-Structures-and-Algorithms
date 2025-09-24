// TC: O(N)
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void reverseArray(vector<int> &arr) {
            int left = 0;
            int right = arr.size() - 1;
            
            while(left <= right){
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        }
    };