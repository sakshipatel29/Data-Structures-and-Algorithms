// TC: O(nlogn) + O(nlogn)
// SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPossible(vector<int> &stalls, int mid, int c) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            lastPos = stalls[i];
        }
        if(cowCount == c) {
            return true;
        }
    }
    return false;
}


int check(vector<int> &stalls, int c) {
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (checkPossible(stalls, mid, c)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans; 
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    cout << check(stalls, c);
    return 0;
}
