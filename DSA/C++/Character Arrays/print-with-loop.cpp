#include<iostream>
using namespace std;

int main() {
    char str[6];
    cin >> str;
    for(char ch : str){
        cout << ch << " ";
    }
    cout<< endl;
    return 0;
}