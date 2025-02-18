//TC: O(NlogN) + O(NlogN) + (N + N)
//SC: O(N+N) + O(N+N)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> sortedArray(vector<int>& arr, vector<int>& arr2) {
    set<int> st;
    
    for (int i = 0; i < arr.size(); i++) {
        st.insert(arr[i]);
    }
    for (int i = 0; i < arr2.size(); i++) {
        st.insert(arr2[i]);
    }

    vector<int> unionArray(st.begin(), st.end());
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
