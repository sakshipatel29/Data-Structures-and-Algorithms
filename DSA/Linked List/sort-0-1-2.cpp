//TC: O(N)
//TC: O(1)

#include <iostream>
#include<vector>
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
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* ConvertArrToLL(vector<int> arr){
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

Node* SortLL(Node* head){
    if(!head || !head->next){
        return head;
    }
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    Node* sortedHead = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return sortedHead;
}


int main() {
    vector<int> arr = {1,0,2,1,2,0,0,0,1,2};
    Node* head = ConvertArrToLL(arr);
    cout << "Original List: ";
    PrintLL(head);
    head = SortLL(head);
    cout << "Sorted List: ";
    PrintLL(head);
    return 0;
}



//output:

//Original List: 1 0 2 1 2 0 0 0 1 2 
//Sorted List: 0 0 0 0 1 1 1 2 2 2 
