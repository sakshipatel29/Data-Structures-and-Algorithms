// Linked List
// Dynamic Memory Allocation
#include<vector>
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    public: 
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};

int main() {
    vector<int> arr = {1,2,3,4};
    Node* z = new Node(arr[2], nullptr);
    cout << z->data;
    return 0;
}

// output: 3