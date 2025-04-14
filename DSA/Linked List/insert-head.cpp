// insert at head
// time complexity: O(1)
// space complexity: O(1)
#include <iostream>
#include<vector>
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
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

void printLL(Node*head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

int main() {
   vector<int> arr = {12,5,7,8};
   Node* head = ConvertArrayToLL(arr);
   int val = 100;
   head = insertHead(head, val);
   printLL(head);
}

// 100 12 5 7 8