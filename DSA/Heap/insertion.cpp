// TC: O(LogN)
// SC: O(N) 

#include <iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;
        
        Heap() {
            arr[0] = -1;
            size = 0;
        } 
        void Insertion(int val){
            
            //add val at last of arr
            size = size + 1;
            int index = size;
            arr[index] = val;
            
            // put the value at correct index
            
            int parent = index/2;
            while(index > 1){
                if(arr[parent] < arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }else{
                    return;
                }
            }
        }
        void print(){
            for(int i = 1; i <= size; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }
};

int main() {
    Heap h;
    h.Insertion(50);
    h.Insertion(55);
    h.Insertion(53);
    h.Insertion(52);
    h.Insertion(54);
    h.print();
    
    return 0;
}

// Output: 55 54 53 50 52