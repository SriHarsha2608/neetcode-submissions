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
    int ans = -1;

    void dfs(TreeNode* root, int& count)
    {
        if(root == NULL)
        {
            return ;
        }

        dfs(root->left, count);

        if(count == 0)
        {
            return ;
        }

        count--;
        if(count == 0)
        {
            ans = root->val;
            return;
        }

        dfs(root->right, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        dfs(root, count);
        return ans;
    }
};
