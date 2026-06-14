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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL)
        {
            return newNode;
        }

        TreeNode* temp = root;
        TreeNode* temp1 = NULL;
        while(temp != NULL)
        {
            if(temp->val > val)
            {
                temp1 = temp;
                temp = temp->left;
            }
            else
            {
                temp1 = temp;
                temp = temp->right;
            }
        }

        if(temp1->val > val)
        {
            temp1->left = newNode;
        }
        else
        {
            temp1->right = newNode;
        }

        return root;
    }
};