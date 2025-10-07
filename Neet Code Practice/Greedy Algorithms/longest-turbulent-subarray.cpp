#include <iostream>
#include <vector>
using namespace std;

//TC: O(N)
//SC: O(1)

class Solution {
    public:
        int maxTurbulenceSize(vector<int>& arr) {
            if(arr.size() == 1) return 1;
            if(arr.size() == 2 && arr[0] == arr[1]){
                return 1;
            }
            if(arr.size() == 2) return arr.size();
            int maxLen = 1;
            int currLen = 2;
            int isGreater = 0;
            if(arr[0] > arr[1]) isGreater = 1;
            for(int i = 2; i < arr.size(); i++){
                if((arr[i-1] > arr[i]) && isGreater == 1){
                    currLen = 2;
                    isGreater = 1;
                }else if((arr[i-1] > arr[i]) && isGreater == 0){
                    currLen++;
                    isGreater = 1;
                }else if(arr[i-1] < arr[i] && isGreater == 1){
                    currLen++;
                    isGreater = 0;
                }else if(arr[i-1] < arr[i] && isGreater == 0){
                    currLen = 2;
                    isGreater = 0;
                }else if(arr[i-1] == arr[i]){
                    currLen = 1;
                }else{
                    currLen = 2;
                }
                maxLen = max(maxLen, currLen);
            }
            return maxLen;
        }
    };