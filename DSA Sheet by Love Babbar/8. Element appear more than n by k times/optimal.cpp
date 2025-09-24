// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        // Function to find all elements in array that appear more than n/k times.
        int countOccurence(vector<int>& arr, int k) {
            unordered_map<int, int> mpp;
            for(int i = 0; i < arr.size(); i++){
                if(mpp[arr[i]]){
                    mpp[arr[i]]++;
                }else{
                    mpp[arr[i]] = 1;
                }
            }
            int n = arr.size();
            int count = 0;
            for(auto it : mpp){
                if(it.second > n/k) count++;
            }
            return count;
        }
    };