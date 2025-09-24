#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(NlogN)
// SC: O(N)

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> res;
        int i = 0;
        int j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                if(res.empty() || res.back() != a[i]) 
                    res.push_back(a[i]);
                i++;
            }else if(a[i] > b[j]){
                if(res.empty() || res.back() != b[j]) 
                    res.push_back(b[j]);
                j++;
            }else{
                if(res.empty() || res.back() != a[i]) 
                    res.push_back(a[i]);
                i++;
                j++;
            }
        }
        while(i < a.size()){
            if(res.empty() || res.back() != a[i]) 
                res.push_back(a[i]);
            i++;
        }
        while(j < b.size()){
            if(res.empty() || res.back() != b[j]) 
                res.push_back(b[j]);
            j++;
        }
        return res;
    }
};