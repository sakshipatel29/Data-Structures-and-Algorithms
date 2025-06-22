//TC: O(N)
//SC: O(N) Height

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

int height(Node*& root, int& maxi){
    if(root == NULL) return 0;
    
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    
    maxi = max(maxi, (lh + rh));
    return 1 + max(lh, rh);
}

int diameter(Node* root){
    int maxi = 0;
    height(root, maxi);
    return maxi;
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
    
    int d = diameter(root);
    cout << d;
    
    return 0;
}

//Output: 6