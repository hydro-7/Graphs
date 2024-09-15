#include<bits/stdc++.h>
using namespace std;

void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
{
    vis[i][j] = 1;
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;

    q.push({i, j});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // traversing neighbours

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for(int k = 0; k < 4; k++)
        {
            int nr = r + dx[k], nc = c + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1' && !vis[nr][nc]) 
            {
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
            
        }
        
    }
    return ;
    
}

int numIslands(vector<vector<char>>& grid) 
{
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> vis(n, vector<int> (m, 0));

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] == '1')
            {
                ans++;
                bfs(i, j, vis, grid);
            }
        }
    }

    return ans;
}
int main()
{

    vector<vector<char>> grid = { {'1', '1', '1', '1', '0'},{'1', '1', '0', '1', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'}};

    int ans = numIslands(grid);

    cout<<ans<<endl;

    return 0;
}
