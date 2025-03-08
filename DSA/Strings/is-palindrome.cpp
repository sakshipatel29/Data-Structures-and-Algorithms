#include<iostream>
#include<string>
#include <algorithm> 
using namespace std;

int main() {
    string str1, str2;
    cin >> str1; // madam
    str2 = str1;  // Copy original string
    reverse(str2.begin(), str2.end());  // Reverse the copy
    if(str1 == str2){
        cout << str1 << " is Palindrome" << endl;
    }else{
        cout << str1 << " is not Palindrome" << endl;
    }
    return 0;
}

// output: madam is Palindrome
// madam is Palindrome

