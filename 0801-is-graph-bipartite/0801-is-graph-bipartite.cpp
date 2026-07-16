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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        for(int i = 0;i<n;i++)
        {
            if(color[i]==0)
            {
                if(!DFS(i,-1,graph,color))
                return false;
            }
        }
        return true;
    }
};