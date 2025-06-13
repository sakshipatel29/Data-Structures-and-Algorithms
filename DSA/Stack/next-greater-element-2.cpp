//TC: O(4N)
//SC: O(2N)
#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NextGreaterElement(vector<int>& arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i = n - 1; i >= 0; i--){ //O(2N)
        while(!st.empty() && (st.top() <= arr[i])){
            st.pop(); //O(N)
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]); //O(N)
    }
    return ans;
}

vector<int> NextGreaterElement2(vector<int> & arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n, -1);
    for(int i = 2*n -1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }
        if(i < n){
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i%n]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4,12,5,3,1,2,5,3,1,2,4,6};
    vector<int> arr2 = arr;
    
    vector<int> arr1 = NextGreaterElement(arr);
    vector<int> arr3 = NextGreaterElement2(arr2);
    
    cout << "Next Greater Element (Linear): " << endl;
    for(int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "Next Greater Element (Circular): " << endl;
    for(int i = 0; i < arr3.size(); i++){
        cout << arr3[i] << " ";
    }
    return 0;
}



//OUTPUT:
// Next Greater Element (Linear): 
// 12 -1 6 5 2 5 6 4 2 4 6 -1 
// Next Greater Element (Circular): 
// 12 -1 6 5 2 5 6 4 2 4 6 12 