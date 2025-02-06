#include<iostream>
using namespace std;

int main(){
    int n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            //Do Something..
        }
    }
}


// Here:

// i = 0 , j [ 0 ]
// i = 1, j [ 0,1]
// i = 2, j [ 0,1,2] 
// ..
// ..
// ..
// i = n, j [ 0,1,2,3,...n]

// which means :

// 1 + 2 +3 +4 + 5 + 6 .... + n = (n * (n+1))/2

// so n**2/2 + n/2

// we can say, Time Complexiy is : O ( N**2)