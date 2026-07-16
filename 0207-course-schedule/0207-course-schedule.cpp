class Solution {
public:
    bool DFS(int src,vector<vector<int>>& p, vector<int>& vis,vector<int>& pvis)
    {
        vis[src]=1;
        pvis[src]=1;
        for(auto it:p[src])
        {
            if(!vis[it])
            {
                if(DFS(it,p,vis,pvis))
                {
                    return true;
                }
            }
            else if(pvis[it])
            {
                return true;
            }
        }
        pvis[src]=0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> p(n);
        for(auto it : pre)
        {
            p[it[0]].emplace_back(it[1]);
        }
        vector<int> vis(n,0);
        vector<int> pvis(n,0);
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                if(DFS(i,p,vis,pvis)) return false;
            }
        }
        return true;
    }
};