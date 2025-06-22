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

vector<int> preOrder(Node*& root){
    vector<int> answer;
    if(root == NULL) return answer;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
        answer.push_back(node->data);
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
    
    vector<int> result = preOrder(root);
    for (auto level : result) {
        cout << level << " ";
    }
    return 0;
}

//Output:1 2 4 5 3 6 7 