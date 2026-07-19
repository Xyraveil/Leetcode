class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 1e8));
        queue<tuple<int,int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [row, col, path] = q.front();
            vis[row][col]=path;
            q.pop();
            if( row <m-1 && vis[row+1][col]>path+1) 
            {
                vis[row+1][col]=path+1;
                q.push({row+1,col,path+1});
            }
            if( row >0 && vis[row-1][col]>path+1) 
            {
                vis[row-1][col]=path+1;
                q.push({row-1,col,path+1});
            }
            if( col <n-1 && vis[row][col+1]>path+1) 
            {
                vis[row][col+1]=path+1;
                q.push({row,col+1,path+1});
            }
            if( col >0 && vis[row][col-1]>path+1) 
            {
                vis[row][col-1]=path+1;
                q.push({row,col-1,path+1});
            }
        }
        return vis;
    }
};