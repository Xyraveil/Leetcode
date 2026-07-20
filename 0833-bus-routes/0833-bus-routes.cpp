class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>> adj;
        if(source==target) return 0;
        int n = routes.size();
        vector<set<int>> adjRoutes(n);
        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int x:routes[i])
            {
                adj[x].emplace_back(i);// adj stores nodes in which a bus stop exists
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int x:routes[i])
            {
                for(int y:adj[x])
                {
                    adjRoutes[i].insert(y);//adjRoutes stores every node a node can go to 
                }
            }
        }
        for(auto i:adj[source])
        {
            vis[i]=1;
            q.push({i,1});
        }

        while(!q.empty())
        {
            int routeNo = q.front().first;
            int busNo = q.front().second;
            vector<int> route = routes[routeNo];  
            q.pop();
            if(find(route.begin(),route.end(),target)!=route.end())
            {
                return busNo;
            }
            
            for(int it:adjRoutes[routeNo])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,busNo+1});
                }
            }
        }
        return -1;
    }
};