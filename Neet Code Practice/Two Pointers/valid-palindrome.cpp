#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)

// Valid Palindrome

// Logic: Remove all non-alphanumeric characters and convert to lowercase

class Solution {
    public:
        bool isPalindrome(string s) {
            string temp;
            for(int i = 0; i < s.size(); i++){
                if(isalnum(s[i])) temp.push_back(tolower(s[i]));
            }
            int left = 0;
            int right = temp.size() - 1;
            while(left < right){
                if(temp[left] != temp[right]) return false;
                left++;
                right--;
            }
            return true;
        }
    };