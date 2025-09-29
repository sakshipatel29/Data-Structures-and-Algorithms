// TC: O(NlogN)
// SC: O(1) and O(N) for return ans.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> getPairs(vector<int>& arr) {
            vector<vector<int>> ans;
            sort(arr.begin(), arr.end());
            int n = arr.size();
            int left = 0;
            int right = n-1;
            while(left < right){
                if(arr[left] + arr[right] == 0){
                    ans.push_back({arr[left], arr[right]});
                    
                    int leftValue = arr[left];
                    int rightValue = arr[right];
                    
                    while(leftValue == arr[left] && left < right) left++;
                    while(rightValue == arr[right] && left < right) right--;
                }else if(arr[left] + arr[right] < 0) left++;
                else right--;
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    };