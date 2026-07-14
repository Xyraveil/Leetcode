class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        int ones =0;
        vector<vector<int>> grid2(m+ 2, vector<int>(n + 2, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid2[i + 1][j + 1] = grid[i][j];
                if (grid[i][j] == 2) {
                    q.push({{i + 1, j + 1}, 0});
                }
                else if(grid[i][j] == 1)
                {
                    ones++;
                }
            }
        }
        if(ones==0) return 0;
        int time=0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = t;
            q.pop();
            if (grid2[row + 1][col] == 1) {
                q.push({{row + 1, col}, t + 1});
                grid2[row + 1][col] =2;
                ones--;
            }

            if (grid2[row][col + 1] == 1) {
                q.push({{row, col + 1}, t + 1});
                grid2[row][col + 1] =2;
                ones--;
            }

            if (grid2[row][col - 1] == 1) {
                q.push({{row, col - 1}, t + 1});
                grid2[row][col-1] =2;
                ones--;
            }

            if (grid2[row - 1][col] == 1) {
                q.push({{row - 1, col}, t + 1});
                grid2[row - 1][col] =2;
                ones--;
            }
        }
        if(!ones) return time;
        else return -1;
    }
};