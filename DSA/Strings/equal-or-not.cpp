#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1 = "saifali";
    string str2 ="saifalii";
    cout << (str1 == str2) << endl;
    return 0;
}

// output: 0
// because str1 and str2 are not equal
// str1 is saifali and str2 is saifalii
// so the output is 0
// if we want to check if the strings are equal, we can use the == operator
// if the strings are equal, the output will be 1
