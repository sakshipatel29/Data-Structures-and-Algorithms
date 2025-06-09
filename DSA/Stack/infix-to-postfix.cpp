//Infix to Postfix
//TC: O(N) + O(N)
//SC: O(N) + O(N)
//https://www.geeksforgeeks.org/infix-to-postfix-conversion-using-stack/
#include <iostream>
using namespace std;
#include <stack>
#include<vector>

int priority(char x){
    if(x == '^'){
        return 3;
    }else if (x == '/' || x == '*'){
        return 2;
    }else if(x == '+' || x == '-'){
        return 1;
    }
    return -1;
}

string InfixToPostfix(string s){
    stack<char> st;
    string ans = "";
    int i = 0;
    int n = s.size();
    while(i < n){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans = ans + s[i];
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if (s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }else{
            if(st.empty()){
                st.push(s[i]);
            }else{
                while(!st.empty() && priority(st.top()) >= priority(s[i])){
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
    return ans;
}

int main() {
    vector<string> testCases = {
        "a+b*(c^d-e)",
        "(a+b)*c",
        "a+b*c",
        "a+b*(c+d)",
        "a*(b+c)/d",
        "(a+b)*(c+d)",
        "A*(B+C)/D-E",
        "x+y*(z-w)/u",
        "a+b-c",
        "(a+b*c-(d/e^f)*g)*h"
    };

    for (const auto& expr : testCases) {
        cout << "Infix: " << expr << "\n";
        cout << "Postfix: " << InfixToPostfix(expr) << "\n";
        cout << "--------------------------\n";
    }

    return 0;
}

//expected output:

// Infix: a+b*(c^d-e)
// Postfix: abcd^e-*+
// --------------------------
// Infix: (a+b)*c
// Postfix: ab+c*
// --------------------------
// Infix: a+b*c
// Postfix: abc*+
// --------------------------
// Infix: a+b*(c+d)
// Postfix: abcd+*+
// --------------------------
// Infix: a*(b+c)/d
// Postfix: abc+*d/
// --------------------------
// Infix: (a+b)*(c+d)
// Postfix: ab+cd+*
// --------------------------
// Infix: A*(B+C)/D-E
// Postfix: ABC+*D/E-
// --------------------------
// Infix: x+y*(z-w)/u
// Postfix: xyzw-*u/+
// --------------------------
// Infix: a+b-c
// Postfix: ab+c-
// --------------------------
// Infix: a+b*(c^d-e)^(f+g*h)-i
// Postfix: abcd^e-fgh*+^*+i-
// --------------------------
