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

Node* InsertBeforeHead(Node* head, int val){
    Node* newNode = new Node(val, head, nullptr);
    head->back = newNode;
    return newNode;
}

Node* InsertBeforeNode(Node* head, int el, int val){
    Node* temp = head;
    if(head->data == el){
        return InsertBeforeHead(head, val);
    }
    while(temp != NULL){
        if(temp->data == el){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

int main() {
    vector<int> arr = {12,0,8,7};
    Node* head = ConvertArrayToDLL(arr);
    head = InsertBeforeNode(head, 7, 10);
    PrintDLL(head);
    return 0;
}

// Output: 12 0 8 10 7