//TC: O(N) + O(N)
//SC: O(2N)
#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextGreaterElement(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && (st.top() <= arr[i])){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> arr1 = NextGreaterElement(arr);
    cout << "Next Greater Element: " << endl;
    for(int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }
    return 0;
}



//OUTPUT:

//Next Greater Element: 
//12 -1 6 5 2 5 6 4 2 4 6 -1 