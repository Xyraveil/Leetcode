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
    bool BFS(int n,vector<vector<int>>& p)
    {
        vector<int> indeg(n,0);
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            for(auto it:p[i]) indeg[it]++;
        }
        int count =0;
        for(int i =0;i<n;i++)
        {
           if(indeg[i]==0) q.push(i);
           
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for(auto it:p[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(count ==n)
        {
            return false;
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> p(n);
        for(auto it : pre)
        {
            p[it[1]].emplace_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> pvis(n,0);
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                //if(DFS(i,p,vis,pvis)) return false;
                if(BFS(n,p)) return false;
            }
        }
        return true;
    }
};