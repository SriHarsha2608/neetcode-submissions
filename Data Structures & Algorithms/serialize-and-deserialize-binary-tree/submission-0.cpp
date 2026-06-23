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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
        {
            return "";
        }

        string ans = "";

        queue<TreeNode*> q;
        
        q.push(root);

        while(!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if(temp == NULL)
            {
                ans.append("#,");
            }
            else
            {
                ans.append(to_string(temp->val) + ',');

                q.push(temp->left);
                q.push(temp->right);
            }
            
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
        {
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();

            getline(s, str, ',');

            if(str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                temp->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if(str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                temp->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};
