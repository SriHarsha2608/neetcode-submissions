class Solution {
private:
    void dfs(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited)
    {
        visited[x][y] = true;
        int n = board.size(), m = board[0].size();

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && board[nx][ny] == 'O')
            {
                dfs(board, nx, ny, visited);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == n - 1 || i == 0 || j == 0 || j == m - 1)
                {
                    if(!visited[i][j] && board[i][j] == 'O')
                    {
                        dfs(board, i, j, visited);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
