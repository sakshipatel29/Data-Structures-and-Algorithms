// TC: O(N)
// SC: O(1)

#include <iostream>
#include <string>
using namespace std;

// Logic: Use two pointers to check if the string is a palindrome
// If the string is not a palindrome, then we can remove one character from the left or right and check if the string is a palindrome
// If the string is a palindrome, then we return true
// If the string is not a palindrome, then we return false

//why O(N)?
//because we are iterating through the string twice
//once to check if the string is a palindrome
//once to check if the string is a palindrome after removing one character
//so the time complexity is O(N)
//and the space complexity is O(1)
//because we are not using any extra space

//why O(1)?
//because we are not using any extra space
//we are only using two pointers
//so the space complexity is O(1)


class Solution {
    public:
        bool isPalindrome(string s, int i, int j){
            while(i < j){
                if(s[i] != s[j]) return false;
                i++;
                j--;
            }
            return true;
        }
        bool validPalindrome(string s) {
            int left = 0;
            int right = s.size() - 1;
            while(left < right){
                if(s[left] == s[right]){
                    left++;
                    right--;
                }else{
                    return isPalindrome(s, left+1, right) || isPalindrome(s, left, right - 1);
                }
            }
            return true;
        }
    };
    