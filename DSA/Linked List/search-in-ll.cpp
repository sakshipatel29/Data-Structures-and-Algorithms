// Time Complexity: O(n)
// Space Complexity: O(1)

// convert array to linked list
// find length of linked list
// search for an element in linked list
// return true if element is present, otherwise false

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};
Node* ConvertArrayToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int LengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}
bool SearchInLL(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main(){
    vector<int> arr = {2,5,7,8};
    Node* head = ConvertArrayToLL(arr);
    cout << "head: " << head->data << endl;
    cout << "length: " << LengthOfLL(head) << endl;
    int val = 15;
    cout << "element is present? " << SearchInLL(head, val) << endl;
    return 0;
}

//output:
// head: 2
// length: 4
// element is present? 0