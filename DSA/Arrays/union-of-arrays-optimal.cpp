//TC: O(N1+N2)
//SC: O(N1+N2)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> sortedArray(vector<int>& arr, vector<int>& arr2) {
    int n1 = arr.size();
    int n2 = arr2.size();
    int i = 0; 
    int j = 0;
    vector<int> unionArray;
    while( i < n1 && j < n2){
        if(arr[i] < arr2[j]) {
            if(unionArray.size() == 0 || unionArray.back() != arr[i]){
                unionArray.push_back(arr[i]);
            }
            i++;
        }else{
            if(unionArray.size() == 0 || unionArray.back() != arr2[j]){
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j < n2){
        if(unionArray.size() == 0 || unionArray.back() != arr2[j]){
                unionArray.push_back(arr2[j]);
            }
            j++;
    }
    while(i < n1){
        if(arr[i] <= arr2[j]) {
            if(unionArray.size() == 0 || unionArray.back() != arr[i]){
                unionArray.push_back(arr[i]);
            }
        i++;
    }
    }
    return unionArray;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> result = sortedArray(arr, arr2);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
