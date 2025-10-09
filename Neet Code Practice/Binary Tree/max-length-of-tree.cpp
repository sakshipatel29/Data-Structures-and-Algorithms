// TC: O(N) // every node is visited once
// SC: O(N) // recursion stack space, in worst case the height of the tree

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
        int maxDepth(TreeNode* root) {
            if(!root) return 0;
            int lh = maxDepth(root->left);
            int rh = maxDepth(root->right);
            return 1 + max(lh, rh);
        }
    };