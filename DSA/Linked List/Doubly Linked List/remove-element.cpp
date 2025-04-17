// Time Complexity: O(n)
// Space Complexity: O(1)

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

Node* RemoveHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* RemoveTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    Node* prev = head;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node* RemoveElement(Node* head, int k){
    if(head == NULL) return NULL;
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(prev == NULL && front == NULL){
        return NULL;
    } else if(prev == NULL){
        return RemoveHead(head);
    } else if(front == NULL){
        return RemoveTail(head);
    }
    prev->next = front;
    front->back = prev;
    return head;
}

int main() {
    vector<int> arr = {12,0,8,7};
    Node* head = ConvertArrayToDLL(arr);
    head = RemoveElement(head,7);
    PrintDLL(head);
    return 0;
}

// Output: 12 0 8