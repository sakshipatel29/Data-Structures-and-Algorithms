#include <iostream>
// #include<bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

//TC: O(N)
//SC: O(1)

class Solution {
    public:
        string gcdOfStrings(string str1, string str2) {
           if(str1 + str2 != str2 + str1) return "";
    
           return str1.substr(0, gcd(str1.length(), str2.length()));
        }
    };