//descending order

#include <iostream>
#include <vector>
using namespace std;

int fn(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] >= pivot && i < high ){
            i++;
        }
        while(arr[j] < pivot && j > low){
            j--;
        }
        if( i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int p_index = fn(arr, low, high);
        quickSort(arr, low, p_index - 1);
        quickSort(arr, p_index + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<< arr[i] << " ";
    }
    return 0;
}