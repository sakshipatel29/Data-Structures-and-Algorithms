#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// TC: O(N)
// SC: O(N)

class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;
        for(int i = 0; i < a.size(); i++){
            st.insert(a[i]);
        }
        for(int i = 0; i < b.size(); i++){
            st.insert(b[i]);
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};