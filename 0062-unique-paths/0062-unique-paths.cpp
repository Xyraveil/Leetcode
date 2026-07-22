class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> A(m,vector<int>(n));
        A[0][0]=1;

        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+1<m) A[i+1][j]+=A[i][j];
                if(j+1<n) A[i][j+1]+=A[i][j];
            }
        }
        return A[m-1][n-1];

    
    }
};