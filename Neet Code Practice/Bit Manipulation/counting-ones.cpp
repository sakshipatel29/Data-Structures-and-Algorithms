#include <iostream>
#include <vector>
using namespace std;

//TC: O(NlogN)
//SC: O(N)

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> ans;
            for(int i = 0; i <= n; i++){
                int res = 0;
                int temp = i;
                while(temp){
                    temp = temp & (temp-1);
                    res++;
                }
                ans.push_back(res);
            }
            return ans;
        }
    };