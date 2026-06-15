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
    map<TreeNode*, int> mpp;

    void intialise(TreeNode* root)
    {
        if(root == NULL)
        {
            return ;
        }
        intialise(root->left);
        mpp[root] = -1;
        intialise(root->right);
    }

    int helper(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        if(mpp[root] != -1)
        {
            return mpp[root];
        }
        int exclude = helper(root->left) + helper(root->right);
        int include = root->val;

        if(root->left)
        {
            include += helper(root->left->left);
            include += helper(root->left->right);
        }

        if(root->right)
        {
            include += helper(root->right->left) + helper(root->right->right);
        }

        return mpp[root] = max(include, exclude);
    }
    

    int rob(TreeNode* root) {
        intialise(root);
        return helper(root);
    }
};