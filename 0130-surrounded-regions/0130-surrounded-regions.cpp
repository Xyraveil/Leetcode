class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i < m - 1) {
                if (board[i + 1][j] == 'O') {
                    board[i+1][j] = 'S';
                    q.push({i+1, j});
                }
            }
            if (i > 0) {
                if (board[i - 1][j] == 'O') {
                    board[i - 1][j] = 'S';
                    q.push({i-1, j});
                }
            }
            if (j<n - 1) {
                if (board[i][j + 1] == 'O') {
                    board[i][j+1] = 'S';
                    q.push({i, j+1});
                }
            }
            if (j > 0) {
                if (board[i ][j- 1] == 'O') {
                    board[i ][j- 1] = 'S';
                    q.push({i, j- 1});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'S';
                bfs(i, 0, board);
            }
            if (board[i][n - 1] == 'O') {
                board[i][n-1] = 'S';
                bfs(i, n - 1, board);
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'S';
                bfs(0, j, board);
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = 'S';
                bfs(m - 1, j, board);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
                else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
};