//TC: O(N)
//SC: O(N) Auxiliary Space

#include <iostream>
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

void inOrder(Node* root){
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << "-->";
    inOrder(root->right);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inOrder(root);
    return 0;
}

//Output:  4-->2-->5-->1-->6-->3-->7