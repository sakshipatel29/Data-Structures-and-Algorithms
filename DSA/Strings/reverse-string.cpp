#include<iostream>
#include<string>
#include <algorithm> 
using namespace std;

int main() {
    string str1;
    cin >> str1; // sakshi
    cout<< str1<<endl;
    reverse(str1.begin(), str1.end());
    cout<< str1;
    return 0;
}