/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool dfs(TreeNode* root, int minimum, int maximum)
    {
        if(root == NULL)
        {
            return true;
        }

        if(root->val <= minimum || root->val >= maximum)
        {
            return false;
        }

        bool leftValid = dfs(root->left, minimum, root->val);
        bool rightValid = dfs(root->right, root->val, maximum);

        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
};
