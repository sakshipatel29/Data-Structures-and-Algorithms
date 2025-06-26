//TC: O(N)
//SC: O(H)

#include <iostream>
#include<vector>
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

bool isPath(Node* root, vector<int>& arr, int value){
    if(!root) return false;
    arr.push_back(root->data);
    if(root->data == value){
        return true;
    }
    if(isPath(root->left, arr, value) || isPath(root->right, arr, value)){
        return true;
    } 
    arr.pop_back();
    return false;
}

vector<int> getPath(Node* root, int value){
    vector<int> arr;
    if(root == NULL) return arr;
    isPath(root, arr, value);
    return arr;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->right->left = new Node(9);
    root->right->left->left = new Node(10);
    root->right->right->left = new Node(11);
    root->left->left->right = new Node(12);
    root->left->right->right = new Node(13);
    root->right->left->right = new Node(14);
    root->right->right->right = new Node(15);
    vector<int> answer;
    answer = getPath(root,15);
    for(auto ans : answer){
        cout << ans << "-->";
    }
    return 0;
}

//OUTPUT: 1-->3-->7-->15