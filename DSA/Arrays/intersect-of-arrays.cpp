//TC: O(N1*N2)
//SC: O(N)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> sortedArray(vector<int>& arr, vector<int>& arr2) {
    int n1 = arr.size();
    int n2 = arr2.size();
    int i = 0; 
    int j = 0;
    vector<int> ans;
    int vis[n2] = {0};
    for(i = 0; i< n1; i++){
        for(j = 0; i< n2; j++){
            if(arr[i] == arr2[j] && vis[j] == 0){
                ans.push_back(arr[i]);
                vis[j] = 1;
                break;
            }
            if(arr2[j] > arr[i]) break;
        }
    }
    return ans;
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
