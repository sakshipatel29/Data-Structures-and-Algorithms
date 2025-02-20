//TC: O(2N)
//SC: O(1)


#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subArraySum(vector<int>& arr, int k){
    long long sum = arr[0];
    int maxLen = 0;
    int left = 0, right = 0;
    int n = arr.size();
    while( right < n){
        if(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right - left  + 1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << subArraySum(arr,k);
    return 0;
}