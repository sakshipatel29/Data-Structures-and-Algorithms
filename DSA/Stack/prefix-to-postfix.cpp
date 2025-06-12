// Postfix to Prefix
//Prefix to Postfix
//TC: O(N) + O(N)
//SC: O(N)
#include <iostream>
#include<stack>
#include <string>
using namespace std;

string PrefixToPostfix(string s){
    stack<string> st;
    int n = s.size();
    int i = n-1;
    while(i >= 0){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string con = s1 + s2 + s[i];
            st.push(con);
        }
        i--;
    }
    return st.top();
}

string PostfixToPrefix(string s){
    stack<string> st;
    int n = s.size();
    int i = 0;
    while( i < n){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1,s[i]));
        }else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string con = s[i] + s2 + s1;
            st.push(con);
        }
        i++;
    }
    return st.top();
}


int main() {
    string stt1 = "AB-DE+F*/";
    string stt2 = "/-AB*+DEF";
    string prefix1 = PostfixToPrefix(stt1);
    cout << "Postfix to Prefix : "<< prefix1 << endl; 
    string postfix = PrefixToPostfix(stt2);
    cout << "Prefix to Postfix : " << postfix << endl;
    return 0;
}

//output: 
// Postfix to Prefix : /-AB*+DEF
// Prefix to Postfix : AB-DE+F*/