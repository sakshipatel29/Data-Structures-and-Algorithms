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

Node* InsertAfterHead(Node* head, int val){
    Node* front = head->next;
    Node* newNode = new Node(val, front, head);
    head->next = newNode;
    front->back = newNode;
    return head;
}

Node* InsertAfterNode(Node* head, int el, int val){
    if(head == NULL){
        return new Node(val);
    }
    if(head->data == el){
        return InsertAfterHead(head, val);
    }
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == el){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* newNode = new Node(val, front, temp);
    temp->next = newNode;
    return head;
}

int main() {
    vector<int> arr = {12,0,8,7};
    Node* head = ConvertArrayToDLL(arr);
    head = InsertAfterNode(head, 12, 10);
    head = InsertAfterNode(head, 8, 11);
    PrintDLL(head);
    return 0;
}

// Output: 12 10 0 8 11 7