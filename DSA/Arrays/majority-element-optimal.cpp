//Moore's Voting Algorithm
//TC: O(N) + O(N)
//SC: O(1)

#include <iostream>
#include<map>
using namespace std;

int majorityElement(int arr[], int n){
    int count = 0;
    int el;
    for(int i = 0; i < n; i++){
        if(count == 0){
            count = 1;
            el = arr[i];
        }
        else if(arr[i] == el){
            count++;
        }else{
            count--;
        } 
    }
    int count2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == el){
            count2++;
        }
    }
    if(count2 > n/2){
            return el;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >>arr[i];
    }
    cout << majorityElement(arr,n);
    return 0;
}