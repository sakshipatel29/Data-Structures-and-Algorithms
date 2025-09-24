// TC: O(NlogN)
// SC: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
      // Function to find all elements in array that appear more than n/k times.
        int countOccurence(vector<int>& arr, int k) {
            int n = arr.size();
            sort(arr.begin(), arr.end());
            int count = 1;
            int total = 0;
            for(int i = 1; i < arr.size();i++){
                if(arr[i] == arr[i-1]){
                    count++;
                }else{
                    if(count > n/k) total++;
                    count = 1;
                }
            }
            if(count > n/k) total++;
            
            return total;
        }
    };