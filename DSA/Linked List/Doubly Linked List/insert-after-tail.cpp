#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* ConvertArrayToDLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void PrintDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* InsertAfterTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newNode = new Node(val, nullptr, tail);
    tail->next = newNode;
    return head;
}

int main() {
    vector<int> arr = {12,0,8,7};
    Node* head = ConvertArrayToDLL(arr);
    head = InsertAfterTail(head, 10);
    head = InsertAfterTail(head, 11);
    PrintDLL(head);
    return 0;
}

// Output: 12 0 8 7 10 11