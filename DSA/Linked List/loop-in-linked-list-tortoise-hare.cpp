//Detect loop in Linked List, Tortoise Hare Method
//TC: O(N)
//SC: O(1)
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

bool LoopInLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
    
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    Node* head = ConvertArrayToLL(arr);

    Node* temp = head;
    Node* loopNode = nullptr;
    while(temp->next != nullptr){
        if(temp->data == 3) loopNode = temp;
        temp = temp->next;
    }
    temp->next = loopNode;

    if(LoopInLL(head) == true){
        cout << "True";
    }else{
        cout << "False";
    }
    return 0;
}

//output: True
