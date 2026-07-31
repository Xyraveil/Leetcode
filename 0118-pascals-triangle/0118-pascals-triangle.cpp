class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(numRows==1) return ans;
        ans.push_back({1,1});
        if(numRows==2) return ans;
        int prev = 1;
        for(int i =0;i<numRows-2;i++)
        {
            vector<int> temp;
            temp.emplace_back(1);
            for(int j=0;j<ans[prev].size()-1;j++)
            {
                temp.emplace_back(ans[prev][j]+ans[prev][j+1]);
            }
            temp.emplace_back(1);
            ans.push_back(temp);
            prev++;
        }
        return ans;
    }
};