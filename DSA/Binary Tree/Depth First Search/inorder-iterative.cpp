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

vector<int> inOrder(Node*& root){
    vector<int> answer;
    if (root == NULL) return answer;
    stack<Node*> st;
    Node* node = root;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            answer.push_back(node->data);
            node = node->right;
        }
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
    
    vector<int> result = inOrder(root);
    for (auto level : result) {
        cout << level << " ";
    }
    return 0;
}

//Output:4 2 5 1 6 3 7 