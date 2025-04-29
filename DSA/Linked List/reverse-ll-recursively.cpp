//TC: O(n)
//SC: O(n)
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
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* ConvertArrayToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void PrintLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* ReverseLLRecursively(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = ReverseLLRecursively(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    vector<int> arr = {12,8,0,7};
    Node* head = ConvertArrayToLL(arr);
    head = ReverseLLRecursively(head);
    PrintLL(head);
    return 0;
}

//output: 7 0 8 12