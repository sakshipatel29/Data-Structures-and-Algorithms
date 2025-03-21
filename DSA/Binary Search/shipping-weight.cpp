// Time Complexity: O(n log m)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;
class Solution {
public:
    bool possible(vector<int>& weights, int mid, int days){
        int sum = 0;
        int day = 1;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            if(sum > mid){
                day += 1;
                sum = weights[i];
            }
        }
        if(day <= days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if(possible(weights, mid, days)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << sol.shipWithinDays(weights, days) << endl;
    return 0;
}