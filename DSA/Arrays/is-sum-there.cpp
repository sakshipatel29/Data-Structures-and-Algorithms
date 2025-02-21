//TC: O(N*logN)
//SC: O(N)
#include <iostream>
#include <map>
using namespace std;

string isSumThere(int arr[], int target, int n){
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        int a = arr[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            return "YES";
        }
        mpp[a] = i;
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