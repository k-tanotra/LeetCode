class Solution {
public:
    pair<int,int> bfs(vector<vector<int>> &g,int startNode){
        int n = g.size();
        vector<bool> visited(n,false);
        queue<pair<int,int>> q;
        q.push({startNode,0});
        int mx = 0;
        int mxIdx = startNode;
        while(!q.empty()){
            int idx = q.front().first;
            int dist = q.front().second;
            if(dist>=mx){
                mx = dist;
                mxIdx = idx;
            }
            visited[idx] = true;
            q.pop();
            for(int i=0;i<g[idx].size();i++){
                if(!visited[g[idx][i]]){
                    q.push({g[idx][i],dist+1});
                }
            }
        }
        return {mx,mxIdx};
    }
    int getDiameter(vector<vector<int>> &g){
        pair<int,int> a = bfs(g,0);
        pair<int,int> b = bfs(g,a.second);
        return b.first;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> g1(n+1);
        vector<vector<int>> g2(m+1);
        for(int i=0;i<edges1.size();i++){
            g1[edges1[i][0]].push_back(edges1[i][1]);
            g1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++){
            g2[edges2[i][0]].push_back(edges2[i][1]);
            g2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int d1 = getDiameter(g1);
        int d2 = getDiameter(g2);
        return max((d1+d1%2)/2 + (d2+d2%2)/2 + 1,max(d1,d2));
    }
};