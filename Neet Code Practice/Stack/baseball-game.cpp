#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
// Baseball Game

// Logic: Use a stack to store the points

class Solution {
    public:
        int calPoints(vector<string>& operations) {
            stack<int> st;
            for (int i = 0; i < operations.size(); i++) {
                if (operations[i] == "+") {
                    int first = st.top();
                    st.pop();
                    int second = st.top();
                    st.push(first);
                    st.push(first + second);
                } else if (operations[i] == "C") {
                    st.pop();
                } else if (operations[i] == "D") {
                    st.push(2 * st.top());
                } else {
                    st.push(stoi(operations[i]));
                }
            }
            int sum = 0;
            while (!st.empty()) {
                sum += st.top();
                st.pop();
            }
            return sum;
        }
    };