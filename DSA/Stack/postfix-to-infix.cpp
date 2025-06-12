// Postfix to Infix
//TC: O(N) + O(N)
//SC: O(N)
#include <iostream>
#include<stack>
#include <string>
using namespace std;

string PostfixToInfix(string s){
    stack<string> st;
    int n = s.size();
    int i = 0;
    while(i < n){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            st.push(string(1, s[i]));
        }else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string con = '(' + s2 + s[i] + s1 + ')';
            st.push(con);
        }
        i++;
    }
    return st.top();
}

int main() {
    string stt = "AB-DE+F*/";
    string infix = PostfixToInfix(stt);
    cout << "Postfix To Infix : "<< infix << endl; 
    return 0;
}

//Output:
// Postfix To Infix : ((A-B)/((D+E)*F))