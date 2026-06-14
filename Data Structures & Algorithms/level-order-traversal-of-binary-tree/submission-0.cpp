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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> levelNodes;
            int size = q.size();

            while(size--)
            {
                TreeNode* topNode = q.front();
                q.pop();

                if(topNode != NULL)
                {
                    levelNodes.push_back(topNode->val);
                    q.push(topNode->left);
                    q.push(topNode->right);
                }
            }
            
            if(!levelNodes.empty())
            {
                ans.push_back(levelNodes);
            }
        }
        return ans;
    }
};
