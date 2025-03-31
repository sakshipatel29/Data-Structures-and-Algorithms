// TC: O(nlogn) + O(nlogn)
// SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int func(vector<int>& arr, int mid){
    int count = 1;
    long long ans = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(ans + arr[i] <= mid){
            ans += arr[i];
        }else{
            count++;
            ans = arr[i];
        }
    }
    return count;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m > n) return -1;
    if (m == n) return *max_element(arr.begin(), arr.end());
    int low = *max(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);
    int ans = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (func(arr, mid) <= m) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};
    int n = 4;
    int m = 2;
    cout << findPages(arr, n, m);
    return 0;
}