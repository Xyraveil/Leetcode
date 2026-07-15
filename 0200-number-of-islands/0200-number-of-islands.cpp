class Solution {
public:
    void BFS(int row, int col, vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        queue<pair<int,int>> q;int n = grid.size();
        int m = grid[0].size();
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty())
        {
            int R = q.front().first;
            int C = q.front().second;
            q.pop();
            int rowdir[] = {1,0,0,-1};
            int coldir[] ={0,1,-1,0};
            for(int i =0;i<4;i++)
            {
                int x = R+ rowdir[i];
                int y = C+ coldir[i];
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y]&& grid[x][y]=='1')
                {
                    q.push({x,y});
                    vis[x][y] =1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int islands =0;
        for(int i = 0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    islands++;
                    BFS(i,j,grid,vis);
                }
            }
        }
        return islands;
    }
};