// array reverse with 1 variable
#include <iostream>
using namespace std;

void fn(int i, int arr[],int n){
    if(i >= n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    fn(i+1, arr, n);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fn(0,arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}