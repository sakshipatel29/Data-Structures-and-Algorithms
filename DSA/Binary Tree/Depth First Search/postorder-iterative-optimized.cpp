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

vector<int> postOrder(Node*& root){
    vector<int> answer;
    if(root == NULL) return answer;
    stack<Node*> st;
    Node* current = root;
    while(current != NULL || !st.empty()){
        if(current != NULL){
            st.push(current);
            current = current->left;
        }else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                answer.push_back(temp->data);
                while(!st.empty() && (temp == st.top()->right)){
                    temp = st.top();
                    st.pop();
                    answer.push_back(temp->data);
                }
            }else{
                current = temp;
            }
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
    
    vector<int> result = postOrder(root);
    for (auto level : result) {
        cout << level << " ";
    }
    return 0;
}

//Output:4 5 2 6 7 3 1