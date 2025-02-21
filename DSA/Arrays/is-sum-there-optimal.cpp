// TC: O(N) + O(NlogN)
// SC: O(1)
#include <iostream>
#include <map>
using namespace std;

string isSumThere(int arr[], int target, int n){
    int left = 0;
    int right = n - 1;
    while(left < right){
        if(arr[left] + arr[right] == target){
            return "YES";
        }else if(arr[left] + arr[right] < target){
            left++;
        }else{
            right--;
        }
    }
    return "NO";
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >>arr[i];
    }
    int target;
    cin >> target;
    cout << isSumThere(arr, target, n);
    return 0;
}