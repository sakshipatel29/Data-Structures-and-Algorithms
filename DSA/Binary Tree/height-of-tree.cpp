//TC: O(N)
//SC: O(N) --> in worst case if it is a skew tree

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
    int rh = height(root->right);
    
    return 1 + max(lh, rh);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int h = height(root);
    cout << "Height: " << h;
    return 0;
}

//Output: Height: 3