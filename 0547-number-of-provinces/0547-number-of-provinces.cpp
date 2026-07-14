class Solution {
private:
    void dfs(int src,vector<vector<int>>& isConnected,vector<int>& vis,int n )
    {
        vis[src]=1;
        for(int i = 0;i<n;i++)
        {
            
            if(isConnected[src][i])
            {
                if(!vis[i]) dfs(i,isConnected,vis,n);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<int> vis(n,0);
        int provs =0;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis,n);
                provs++;
            }
        }
        return provs;
    }
};