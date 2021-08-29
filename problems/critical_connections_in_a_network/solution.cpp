class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> res;
    vector<bool> visited;
    vector<int> low,disc,parent;
    
    void dfs(int u){
        static int time = 0;
        visited[u] = true;
        low[u] = disc[u] = ++time;
        
        for(int v: adj[u]){
            if(!visited[v]){
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u],low[v]);
                if(low[v]>disc[u]){
                    res.push_back({u,v});
                }
            }
            else if(parent[u]!=v){
                low[u] = min(low[u],disc[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        visited.assign(n,false);
        parent.assign(n,-1);
        low.resize(n);
        disc.resize(n);
        
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        
        return res;
    }
};