#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)

// Reverse String using two pointers

class Solution {
    public:
        void reverseString(vector<char>& s) {
            int left = 0;
            int right = s.size() - 1;
            while(left < right){
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
        }
    };