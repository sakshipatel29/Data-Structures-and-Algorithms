// TC: O(N)
// SC: O(N) + O(logN)

#include <iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;
        
        Heap() {
            arr[0] = -1;
            size = 0;
        } 
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = i * 2;
    int right = (i * 2) + 1;
    
    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {

    int arr[10] = {-1, 54, 53, 55, 52, 56};
    int n = 5;
    for(int i = n/2; i > 0; i--){
        heapify(arr, n, i);
    }
    cout << "printing heapified : " << endl;
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " " ;
    }
    
    return 0;
}

// Output: printing heapified : 
// 56 54 55 52 53 
