class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int m = image[0].size();
        int n = image.size();
        int sCol = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row <n-1 &&  image[row+1][col]==sCol)
            {
                image[row+1][col]=color;
                q.push({row+1,col});
            }
            if(col<m-1 &&  image[row][col+1]==sCol)
            {
                image[row][col+1]=color;
                q.push({row,col+1});
            }
            if(col>0 &&  image[row][col-1]==sCol)
            {
                image[row][col-1]=color;
                q.push({row,col-1});
            }
            if(row>0 &&  image[row-1][col]==sCol)
            {
                image[row-1][col]=color;
                q.push({row-1,col});
            }
        }
        return image;

    }
};