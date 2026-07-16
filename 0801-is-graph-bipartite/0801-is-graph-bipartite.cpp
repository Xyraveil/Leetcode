class Solution {
public:
    bool DFS(int src,int col, vector<vector<int>>& graph, vector<int>& color )
    {
        color[src]=col;
        for(auto it: graph[src])
        {
            if(color[it]==0)
            {
                color[it]= -col;
                if(!DFS(it,color[it],graph,color))
                return false;
            }
            else if(color[it]==col)
            {
                return false;
            }
        }
        return true;
    }
    bool BFS(int src,int col, vector<vector<int>>& graph, vector<int>& color )
    {
        queue<int> q;
        q.push(src);
        color[src]=-1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==0)
                {
                    q.push(it);
                    color[it]=-color[node];
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        for(int i = 0;i<n;i++)
        {
            if(color[i]==0)
            {
                if(!BFS(i,-1,graph,color))
                return false;
            }
        }
        return true;
    }
};