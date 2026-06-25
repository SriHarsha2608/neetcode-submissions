class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int count1 = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1)
                {
                    count1++;
                }
            }
        }
        
        int timer = 0;
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};

                for(int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];

                    if(nx >= 0 && nx < n && ny >=0 && ny < m && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        count1--;
                    }
                }
            }
            if(!q.empty())
            timer++;
        }

        if(count1 == 0)
        {
            return timer;
        }

        return -1;

    }
};
