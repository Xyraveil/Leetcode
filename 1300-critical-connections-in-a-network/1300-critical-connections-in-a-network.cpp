class Solution {
public:
    int timer =0;
    void dfs(int node,int parent ,vector<int>& vis,vector<vector<int>> &adj,vector<int>&step,vector<int>&low,vector<vector<int>>& ans)
    {
        vis[node]=1;
        step[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it == parent) continue;
            if(!vis[it])
            {
                dfs(it,node,vis,adj,step,low,ans);
                low[node]=min(low[node],low[it]);
                if(low[it]>step[node])
                {
                    ans.push_back({it,node});
                }
            }
            else
            {
                low[node]= min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto edge:connections)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> vis(n,0);
        vector<int> step(n);
        vector<int> low(n);
        vector<vector<int>> ans;
        dfs(0,-1,vis,adj,step,low,ans);
        return ans;
    }
};