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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &mpp)
    {
        if(preStart > preEnd || inStart > inEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int index = mpp[root->val];
        int numsLeft = index - inStart;

        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, index - 1, mpp);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, index + 1, inEnd, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }
};
