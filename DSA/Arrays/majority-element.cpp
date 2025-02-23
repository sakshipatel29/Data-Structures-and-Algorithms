//TC: O(NlogN) + O(N)
//SC: O(N)

#include <iostream>
#include<map>
using namespace std;

int majorityElement(int arr[], int n){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]] += 1;
    }
    for(auto it: mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >>arr[i];
    }
    cout << majorityElement(arr,n);
    return 0;
}