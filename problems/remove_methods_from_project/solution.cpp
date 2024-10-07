class Solution {
public:
    void dfs(int k,vector<vector<int>> &adj, unordered_set<int> &sus, vector<bool> &visited){
        if(visited[k]){
            return;
        }
        sus.insert(k);
        visited[k]=true;
        for(int i=0;i<adj[k].size();i++){
            if(!visited[adj[k][i]]){
                dfs(adj[k][i],adj,sus,visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        unordered_set<int> sus;
        unordered_set<int> ivk;
        vector<bool> visited(n, false);
        dfs(k,adj,sus,visited);
        vector<int> res;
        bool f = false;
        for(int i=0;i<invocations.size();i++){
           if(sus.find(invocations[i][0])==sus.end() && sus.find(invocations[i][1])!=sus.end()){
                ivk.insert(invocations[i][1]);
                f = true;
           }
        }

        for(int i=0;i<n;i++){
            if(f){
                res.push_back(i);
            }
            else if(sus.find(i)==sus.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};
