//parameterised recursion: 
// factorial:

#include<iostream>
using namespace std;

void fn(int i,int fac){
    if( i < 1){
        cout << fac;
        return;
    }
    fn(i-1, fac * i);
}

int main(){
    int n;
    cin >> n;
    fn(n,1);
    return 0;
}   