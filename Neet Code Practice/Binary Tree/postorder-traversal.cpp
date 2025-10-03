// Iterative Solution
// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> st;
            if(root == NULL) return ans;
            st.push(root);
            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                if(node->left) st.push(node->left);
                if(node->right) st.push(node->right);
                ans.push_back(node->val);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };

// Recursive Solution

class Solution {
    public:
        void postorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return;
    
            postorder(root->left, ans);
            postorder(root->right, ans);
            
            ans.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            postorder(root, ans);
            return ans;
        }
};