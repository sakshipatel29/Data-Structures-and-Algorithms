// TC: O(H) + O(H) + O(N) ~~ O(N)
// SC : O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    public: 
        int data;
        struct Node* left;
        struct Node* right;
    
        Node(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};

bool isLeaf(Node*& root){
    if((root->left == NULL) && (root->right == NULL)) return true;
    return false;
}

void leftBoundary(Node*& root, vector<int>& answer){
    Node* current = root->left;
    while(current){
        if(!isLeaf(current)) answer.push_back(current->data);
        if(current->left){
            current = current->left;
        }else{
            current = current->right;
        } 
    }
}

void rightBoundary(Node*& root, vector<int>& answer){
    Node* current = root->right;
    vector<int> temp;
    while(current){
        if(!isLeaf(current)) temp.push_back(current->data);
        if(current->right){
            current = current->right;
        }else{
            current = current->left;
        }
    }
    for(int i = temp.size() - 1; i >= 0; --i){
        answer.push_back(temp[i]);
    }
}

void addLeaves(Node*& root, vector<int>& answer){
    if(root == NULL) return;
    if(isLeaf(root)) {
        answer.push_back(root->data);
    }
    addLeaves(root->left, answer);
    addLeaves(root->right, answer);
}

vector<int> Boundary(Node* root){
    vector<int> answer;
    if(root == NULL) return answer;
    //First add root
    if( !isLeaf(root)) answer.push_back(root->data);
    //then add left nodes
    leftBoundary(root, answer);
    //then add leaf nodes
    addLeaves(root, answer);
    //at last add right nodes
    rightBoundary(root, answer);
    return answer;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = Boundary(root);
    for(auto res : ans){
        cout << res << "-->";
    }
    return 0;
}

//Output: 1-->2-->4-->5-->6-->7-->3