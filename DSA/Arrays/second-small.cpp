//O(N)

#include <iostream>
#include <climits>
using namespace std;

int main() {
   int n;
   cin >> n;
   int arr[n];
   for(int i = 0; i<n; i++){
       cin >> arr[i];
   }
   int smallest = arr[0];
   int secondsmallest = INT_MAX;
   for(int i = 1; i < n; i++){
      if(arr[i] < smallest){
          secondsmallest = smallest;
          smallest = arr[i];
      }else if(arr[i] != smallest && arr[i] < secondsmallest){
          secondsmallest = arr[i];
      }
   }
   cout<< "second smallest: " << secondsmallest << endl;
   
   return 0;
}