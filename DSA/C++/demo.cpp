#include<iostream>
using namespace std;

void doSomething(int arr[], int n){
    arr[0] += 100;
    cout << "array in something:" << arr[0];
}

int main(){
    int n = 10;
    int arr[n];
    for( int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "array in main before:" << arr[0];
    doSomething(arr, n);
    cout << "array in main:" << arr[0];
    return 0;
}