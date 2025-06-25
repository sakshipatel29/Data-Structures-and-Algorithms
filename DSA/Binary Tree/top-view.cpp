// TC: O(N)
// SC: O(N)

#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct Node {
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

vector<int> topView(Node* root){
    vector<int> answer;
    if(root == NULL) return answer;
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()){
            mpp[line] = node->data;
        }
        if(node->left){
            q.push({node->left, line - 1});
        }
        if(node->right){
            q.push({node->right, line + 1});
        }
    }
    for(auto p : mpp){
        answer.push_back(p.second);
    }
    return answer;
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
    vector<int> ans = topView(root);
    cout << "Top View Traversal: "<< endl;
    for(auto p : ans){
        cout << p << " --> ";
    }
    return 0;
}


//OUTPUT: 8 --> 4 --> 2 --> 1 --> 3 --> 7 --> 15