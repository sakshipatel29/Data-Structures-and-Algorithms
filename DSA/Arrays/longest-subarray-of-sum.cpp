//TC: If we use ordered map --> O(NlogN)
//TC: If we use unordered map --> O(N*N)
//SC: O(N)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subArraySum(vector<int>& arr, int k){
    long long sum = 0;
    std::map<long long , int> preSumMap;
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
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