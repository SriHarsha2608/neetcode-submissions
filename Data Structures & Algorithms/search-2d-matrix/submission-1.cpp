class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int lowRow = 0, highRow = n - 1;
        int ansRow = 0;
        while(lowRow <= highRow)
        {
            int midRow = (lowRow + highRow) / 2;
            if(matrix[midRow][0] <= target)
            {
                ansRow = midRow;
                lowRow = midRow + 1;
            }   
            else
            {
                highRow = midRow - 1;
            }
        }

        int lowCol = 0, highCol = m - 1;
        int ansCol = 0;
        while(lowCol <= highCol)
        {
            int midCol = (lowCol + highCol) / 2;
            if(matrix[ansRow][midCol] <= target)
            {
                ansCol = midCol;
                lowCol = midCol + 1;
            }
            else
            {
                highCol = midCol - 1;
            }
        }

        return matrix[ansRow][ansCol] == target;
    }
};
