class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& brd) {
        const int MOD = 1e9+7;
        int n = brd.size();
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<vector<int>> ways(n,vector<int>(n,0));
        for(int i = n-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(brd[i][j]=='X')
                board[i][j] =-1;
                else board[i][j] =brd[i][j]-'0';
            }
        }
        board[0][0]=0;
        board[n-1][n-1] =0;
        ways[n-1][n-1]=1;
        for(int i = n-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==n-1 && j==n-1)
                continue;
                if(board[i][j]==-1)
                continue;
                int add=-1;
                if(j+1<n && board[i][j+1]!=-1 && ways[i][j+1] > 0)
                {
                    if(board[i][j+1]>add)
                    {
                        add =board[i][j+1];
                        ways[i][j]=ways[i][j+1];
                    }
                    else if(board[i][j+1] == add)
                    {
                        ways[i][j] = (ways[i][j]+ ways[i][j+1])%MOD;
                    }
                }
                if(i+1<n && board[i+1][j]!=-1  && ways[i+1][j] > 0)
                {
                    if(board[i+1][j]>add)
                    {
                        add =board[i+1][j];
                        ways[i][j]=ways[i+1][j];
                    }
                    else if(board[i+1][j]==add)
                    {
                        ways[i][j] = (ways[i][j]+ ways[i+1][j])%MOD;
                    }
                }
                if(j+1<n && i+1<n && board[i+1][j+1]!=-1 && ways[i+1][j+1] > 0)
                {
                    if(board[i+1][j+1]>add)
                    {
                        add =board[i+1][j+1];
                        ways[i][j]=ways[i+1][j+1];
                    }
                    else if(board[i+1][j+1]==add)
                    {
                        ways[i][j] = (ways[i][j]+ ways[i+1][j+1])%MOD;
                    }
                }
                if(add == -1)
                {
                    board[i][j] = -1;
                    ways[i][j] = 0;
                }
                else
                {
                    board[i][j] += add;
                }
            }
        }
        if(board[0][0]<0) board[0][0]=0;
        return vector<int>{board[0][0],ways[0][0]};
        
        
    }
};