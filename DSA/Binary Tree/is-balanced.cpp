//TC: O(N)
//SC: O(N)

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node*& root){
    if(root == NULL) return 0;
    
    int lh = height(root->left);
    if (lh == -1) return -1;
    int rh = height(root->right);
    if (rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalanced(Node* root){
    if (height(root) == -1) return false;
    return true;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->left->right = new Node(9);
    
    if(isBalanced(root)) {
        cout << "Tree is Balanced";
    }else {
         cout << "Tree is not Balanced.";
    }
    
    return 0;
}

//Output: Tree is not Balanced.