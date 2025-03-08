#include<iostream>
#include<cstring>
using namespace std;

int main() {
    char str[100];
    cin >> str;
    int s = 0;
    int e = strlen(str) - 1;
    while(s < e){
        swap(str[s++], str[e--]);
    }
    cout << str;
    return 0;
}