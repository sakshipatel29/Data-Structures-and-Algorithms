// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Logic: Use a recursive function to traverse the tree

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : val(val), left(NULL), right(NULL) {}
    };
class Solution {
    public:
        void preorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return;
            ans.push_back(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            preorder(root, ans);
            return ans;
        }
    };


// Iterative Solution
// TC: O(N)
// SC: O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> st;
            if(root == NULL) return {};
            st.push(root);
            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                ans.push_back(node->val);
            }
            return ans;
        }
    };