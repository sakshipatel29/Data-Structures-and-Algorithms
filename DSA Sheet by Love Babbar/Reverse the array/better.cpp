// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        void reverseArray(vector<int> &arr) {
            stack<int> st;
            for(int i = 0; i < arr.size(); i++){
                st.push(arr[i]);
            }
            int j = 0;
            while(!st.empty()){
                arr[j] = st.top();
                st.pop();
                j++;
            }
        }
    };