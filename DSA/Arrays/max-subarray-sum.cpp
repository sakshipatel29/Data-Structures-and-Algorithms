//Kadane's Algorithm
//SC: O(N)
//TC: O(1)

#include <iostream>
#include<map>
#include <climits>
using namespace std;

long long maxSubArraySum(int arr[], int n){
    long long sum = 0;
    long long maxi = LONG_MIN;
    for(int i = 0; i < n ; i++){
        sum += arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >>arr[i];
    }
    cout << maxSubArraySum(arr,n);
    return 0;
}