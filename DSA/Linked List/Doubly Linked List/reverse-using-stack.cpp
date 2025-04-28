// Time Complexity: 2O(n)
// Space Complexity: O(n)

#include <iostream>
#include<vector>
#include<stack>
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

Node* ReverseDLL(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!= NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12,0,8,7,5};
    Node* head = ConvertArrayToDLL(arr);
    ReverseDLL(head);
    PrintDLL(head);
    return 0;
}

// Output: 5 7 8 0 12