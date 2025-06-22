//TC: O(N)
//SC: O(3N)

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

vector<int> postOrder(Node*& root){
    vector<int> answer;
    if(root == NULL) return answer;
    stack<Node*> st1;
    stack<int> st2;
    st1.push(root);
    while(!st1.empty()){
        Node* node = st1.top();
        st1.pop();
        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);
        st2.push(node->data);
    }
    while(!st2.empty()){
        answer.push_back(st2.top());
        st2.pop();
    }
    return answer;
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int> result = postOrder(root);
    for (auto level : result) {
        cout << level << " ";
    }
    return 0;
}

//Output:4 5 2 6 7 3 1