//TC: O(N)
//SC: O(H) Height of the tree

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void changeTree(Node* root) {
    if (root == NULL) return;

    int child = 0;
    if (root->left) child += root->left->data;
    if (root->right) child += root->right->data;

    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;
    if (root->left || root->right) root->data = total;
}

// Level Order Traversal (Breadth First Search)
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        while (levelSize--) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main() {
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    cout << "Before changeTree:\n";
    printLevelOrder(root);

    changeTree(root);

    cout << "\nAfter changeTree:\n";
    printLevelOrder(root);

    return 0;
}

//Output:

// Before changeTree:
// 40 
// 10 20 
// 2 5 30 40 

// After changeTree:
// 150 
// 80 70 
// 40 40 30 40 
