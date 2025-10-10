// TC: O(Nlog(maxi(piles)))
// SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int mini = 1;
            int maxi = *max_element(piles.begin(), piles.end());
            int ans = maxi;
            while(mini <= maxi){
                int mid = mini + (maxi - mini)/2;
                long long hours = 0;
                for(auto& p : piles){
                    hours += (p + mid - 1)/mid;
                }
                if(hours > h) mini = mid + 1;
                else{
                    ans = mid;
                    maxi = mid - 1;
                }
            }
            return ans;
        }
    };