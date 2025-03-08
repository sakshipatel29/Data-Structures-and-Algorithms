#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1 = "sakshi";
    string str2 ="saifali";
    cout << (str1 < str2) << endl;
    return 0;
}

// as per the lexicographical order, sakshi is less than saifali
// so the output is 0
// if we want to check if the strings are greater, we can use the > operator
// if the strings are greater, the output will be 1
// if the strings are equal, the output will be 0
// if the strings are less, the output will be 0
