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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
        {
            return root;
        }

        TreeNode* temp = root;

        while(temp != NULL)
        {
            if(temp->val > p->val && temp->val > q->val)
            {
                temp = temp->left;
            }

            else if(temp->val < p->val && temp->val < q->val)
            {
                temp = temp->right;
            }

            else
            {
                break;
            }
        }

        return temp;
        // TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        // TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        // if(leftNode != NULL && rightNode != NULL)
        // {
        //     return root;
        // }

        // else if(leftNode != NULL)
        // {
        //     return leftNode;
        // }

        // else
        // {
        //     return rightNode;
        // }

    }
};
