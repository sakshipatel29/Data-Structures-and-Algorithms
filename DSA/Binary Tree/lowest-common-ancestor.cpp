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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == NULL || root == p || root == q){
        return root;
    }
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    
    if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{
        return root;
    }
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
    Node* one = root->right->right->left;
    Node* two = root->right->right->right;
    Node* lca = lowestCommonAncestor(root, one, two);
    cout << lca->data;
    return 0;
}

//OUTPUT: 7