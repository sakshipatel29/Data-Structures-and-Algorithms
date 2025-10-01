#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Recursive Solution
//TC: O(N)
//SC: O(N)

class Solution {
    public:
        void inorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return;
    
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            inorder(root, ans);
            return ans;
        }
    };
        
//Iterative Solution
//TC: O(N)
//SC: O(N)
    
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> st;
            TreeNode* node = root;
            while(true){
                if(node != NULL){
                    st.push(node);
                    node = node->left;
                }else{
                    if(st.empty()) break;
                    node = st.top();
                    st.pop();
                    ans.push_back(node->val);
                    node = node->right;
                }
            }
            return ans;
        }
    };