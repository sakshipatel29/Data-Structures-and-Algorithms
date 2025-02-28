// TC: O(N) + O(NlogN)
// SC: O(N)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> LeaderElements(vector<int>& arr, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n - 1; i >= 0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = std::max(maxi, arr[i]);
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    vector<int> leaders = LeaderElements(arr, n);
    for(int i = leaders.size() - 1; i >=0 ;i--){
        cout<< leaders[i] << " ";
    }
    return 0;
}