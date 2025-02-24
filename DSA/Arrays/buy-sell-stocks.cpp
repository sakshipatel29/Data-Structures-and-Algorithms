//TC: O(N)
//SC: O(1)

#include <iostream>
using namespace std;

int buySellStock(int arr[], int n){
    int profit = 0;
    int mini = arr[0];
    for(int i = 1; i < n; i++){
        int cost = arr[i] - mini;
        profit = std::max(cost, profit);
        mini = std::min(mini, arr[i]);
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i< n; i++){
        cin >> arr[i];
    }
    cout<< buySellStock(arr, n);
    return 0;
}