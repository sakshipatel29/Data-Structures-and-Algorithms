#include<iostream>
using namespace std;

int main() {
    char str[100];
    cin >> str;
    int len = 0;
    for(int i = 0; i < str[i] != '\0'; i++){
        len++;
    }
    cout<< "length:" << len << endl;
    return 0;
}