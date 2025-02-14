//tc: O(2N)
//sc: O(1)

#include <iostream>
#include <vector>
using namespace std;

void reverseArray(int arr[], int i, int j){
    while( i < j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int d;
    cin >> d;
    
    d = d % n;
    
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "; 
    }
    
    return 0;
}
