class Solution {
public:
    bool DFS(int src,vector<vector<int>>& p, vector<int>& vis,vector<int>& pvis,stack<int>& S)
    {
        
        vis[src]=1;
        pvis[src]=1;
       
        for(auto it:p[src])
        {
            if(!vis[it])
            {
                if(DFS(it,p,vis,pvis,S))
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
        S.push(src);
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        stack<int> S;
        vector<vector<int>> p(n);
        
        vector<int>Ans;
        for(auto it : pre)
        {
            p[it[1]].emplace_back(it[0]);
        }
        vector<int> empty;
        vector<int> vis(n,0);
        vector<int> pvis(n,0);
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                if(DFS(i,p,vis,pvis,S)) return empty;
              
            }
        }
        while(!S.empty())
        {
            Ans.emplace_back(S.top());
            S.pop();
        }
        return Ans;
    }

};