// Time Complexity: O(n log m)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public: 
    long long timeForNumber(vector<int>& piles, int hours){
        int n = piles.size();
        long long totalHours = 0;
        for(int i = 0; i < n; i++){
            totalHours += ceil((double)piles[i] / (double)hours);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            long long hours = timeForNumber(piles, mid);
            if(hours <= h){
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
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}