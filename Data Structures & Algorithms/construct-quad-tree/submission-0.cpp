/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>>& grid, int lowRow, int highRow, int lowCol, int highCol)
    {
        bool contains0 = false;
        bool contains1 = false;
        for(int i = lowRow; i <= highRow; i++)
        {
            for(int j = lowCol; j <= highCol; j++)
            {
                if(grid[i][j] == 0)
                {
                    contains0 = true;
                }
                else
                {
                    contains1 = true;
                }
            }   
        }
        
        Node* newNode = new Node();
        if(contains0 && contains1)
        {
            newNode->val = true;
            newNode->isLeaf = false;
            newNode->topLeft = helper(grid, lowRow, (lowRow + highRow) / 2, lowCol, (lowCol + highCol) / 2);
            newNode->topRight = helper(grid, lowRow, (lowRow + highRow) / 2, (lowCol + highCol) / 2 + 1, highCol);
            newNode->bottomLeft = helper(grid, (lowRow + highRow) / 2 + 1, highRow, lowCol, (lowCol + highCol) / 2);
            newNode->bottomRight = helper(grid, (lowRow + highRow) / 2 + 1, highRow, (lowCol + highCol) / 2 + 1, highCol);

        }
        else if(contains0)
        {
            newNode->val = false;
            newNode->isLeaf = true;
        }
        else
        {
            newNode->val = true;
            newNode->isLeaf = true;
        }
        return newNode;
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return helper(grid, 0, n - 1, 0, n - 1);
    }
};