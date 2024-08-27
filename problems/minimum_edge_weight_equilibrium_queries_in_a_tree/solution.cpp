class Solution {
public:
    void preprocess(int node, int parent, vector<vector<vector<int>>>& tree, vector<vector<int>>& up,vector<int> &depth) {
        up[node][0] = parent;
        for (int i = 1; i < up[node].size(); i++) {
            if (up[node][i-1] != -1)
                up[node][i] = up[up[node][i-1]][i-1];
        }
        for (auto& child : tree[node]) {
            if (child[0] != parent) {
                depth[child[0]] = depth[node] + 1;
                preprocess(child[0], node, tree, up, depth);
            }
        }
    }

    int lca2(int u, int v, vector<vector<int>>& up,vector<int> &depth) {
        if (depth[u] < depth[v])
            swap(u, v);
        
        int diff = depth[u] - depth[v];
        for (int i = 0; i < up[u].size(); i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if (u == v) return u;
        
        for (int i = up[u].size() - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        
        return up[u][0];
    }
    void rec(vector<vector<vector<int>>> &tree,vector<bool> &visited,vector<vector<int>> &dp,int idx,vector<int> &f){
        visited[idx] = true;
        for(int i=0;i<tree[idx].size();i++){
            if(!visited[tree[idx][i][0]]){
                f[tree[idx][i][1]]++;
                //parent[tree[idx][i][0]].push_back(idx);
                rec(tree,visited,dp,tree[idx][i][0],f);
                f[tree[idx][i][1]]--;
            }
        }
        dp[idx] = f;
    }
    int cal(vector<int> &a,vector<int> &b,vector<int> &c){
        int mx = -1;
        int count = 0;
        for(int i=0;i<27;i++){
            int x = a[i] - c[i];
            int y = b[i] - c[i];
            count += x + y;
            if(mx<x + y){
                mx = x + y;
            }
        }
        return count-mx;
    }
    void print(vector<vector<int>> &parent){
        for(int i=0;i<parent.size();i++){
            for(int j=0;j<parent[i].size();j++){
                cout<<parent[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> dp(n,vector<int>(27,0));
        vector<vector<vector<int>>> tree(n);
        vector<bool> visited(n,false);
        vector<int> f(27,0);
        vector<vector<int>> up;
        vector<int> depth;
        int maxLog = log2(n) + 1;
        up.assign(n, vector<int>(maxLog, -1));
        depth.assign(n, 0);
        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            tree[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        rec(tree,visited,dp,0,f);
        preprocess(0, -1, tree, up,depth);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int lca = lca2(queries[i][0],queries[i][1],up,depth);
            ans.push_back(cal(dp[queries[i][0]],dp[queries[i][1]],dp[lca]));
        }
        return ans;
    }
};