//TC: O(N/2) + O(N/2) + O(2N)
//SC: O(N)

#include <iostream>
#include<stack>
#include <algorithm>
using namespace std;

int priority(char ch){
    if(ch == '^'){
        return 3;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else if(ch == '+' || ch == '-'){
        return 1;
    }
    return -1;
}

string InfixToPrefix(string s){
    stack<char> st;
    string ans = "";
    int i = 0;
    int n = s.size();
    
    //1. reverse string
    reverse(s.begin(), s.end());
    while(i < n){
        if((s[i] >='A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z') || (s[i] >='0' && s[i] <= '9')){
            ans = ans + s[i];
        }else if(s[i] == ')'){
            st.push(s[i]);
        }else if (s[i] == '('){
            while(!st.empty() && st.top() != ')'){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }else {
            if(s[i] == '^'){
                while(!st.empty() && (priority(s[i]) <= priority(st.top()))){
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }else {
                while(!st.empty() && (priority(s[i]) < priority(st.top()))){
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    string s1 = "a*b+c/d";
    string prefix = InfixToPrefix(s);
    string prefix1 = InfixToPrefix(s1);
    cout << "Pre Fix: " << prefix << endl;
    cout << "Pre Fix 1: " << prefix1 << endl;
    return 0;
}

//expected output:
//Pre Fix: *-a/bc-/akl
//Pre Fix 1: *+ab/cd