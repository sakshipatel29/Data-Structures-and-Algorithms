// Prefix to Infix
//TC: O(N) + O(N)
//SC: O(N)
#include <iostream>
#include<stack>
#include <string>
using namespace std;

string PrefixToInfix(string s){
    stack<string> st;
    int n = s.size();
    int i = n-1;
    while(i >= 0){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1,s[i]));
        }else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string con = '(' + s1 + s[i] + s2 + ')';
            st.push(con);
        }
        i--;
    }
    return st.top();
}

int main() {
    string stt1 = "*+PQ-MN";
    string infix1 = PrefixToInfix(stt1);
    cout << "Prefix To Infix : "<< infix1 << endl; 
    return 0;
}

//output: 
// Prefix To Infix : ((P+Q)*(M-N))