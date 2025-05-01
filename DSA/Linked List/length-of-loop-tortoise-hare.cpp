//TC: O(N) + 2log(N)
//SC: O(1)
#include <iostream>
#include<vector>
#include<unordered_map>
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

int findLength(Node* slow, Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow != fast){
        count++;
        fast = fast->next;
    }
    return count;
}

int LoopInLL(Node* head) {
    if(head == NULL || head->next == NULL){
        return 0;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findLength(slow, fast);
        }
    }
    return 0;
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
    int len = LoopInLL(head);
    cout << "Length of loop: " << len << endl;
    return 0;
}

//output: Length of loop: 5