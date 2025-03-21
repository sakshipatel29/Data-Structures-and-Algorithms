//TC if brute: O(NlogN)
// this is optimized: with O(N)

#include <iostream>
using namespace std;

int main() {
   int n;
   cin >> n;
   int arr[n];
   for(int i = 0; i<n; i++){
       cin >> arr[i];
   }
   int largest = arr[0];
   int secondLargest = -1;
   for(int i = 0; i < n; i++){
      if(arr[i] > largest){
          secondLargest = largest;
          largest = arr[i];
      }else if(arr[i] < largest && arr[i]> secondLargest){
          secondLargest = arr[i];
      }
   }
   cout<< "second largest: " << secondLargest << endl;
   
   return 0;
}