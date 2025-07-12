//TC: O(nlogn)
//SC: O(N)

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i * 2;
    int right = (i * 2) + 1;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    } 
}

void heapSort(int arr[], int n){
    int t = n;
    while(t > 1){
        swap(arr[1], arr[t]);
        t--;
        heapify(arr,t,1);
    }
}

int main() {
    int arr[6] = {-1, 50, 55, 53, 54, 52};
    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    heapSort(arr, n);
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }cout << endl;
    
    return 0;
}

//Output: 55 54 53 50 52 
// 50 53 52 54 55 