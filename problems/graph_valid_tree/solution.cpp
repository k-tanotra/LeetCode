class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mat(n,vector<int>());
        
        for(int i=0;i<edges.size();i++){
            mat[edges[i][0]].push_back(edges[i][1]);
            mat[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,bool> m;
        queue<pair<int,int>> q;
        q.push({0,-1});
        while(!q.empty()){
            pair<int,int> x = q.front();
            // cout<<q.front().first<<" "<<q.front().second<<endl;
            m[x.first] = true;
            q.pop();
            for(int i=0;i<mat[x.first].size();i++){
                if(mat[x.first][i]!=x.second){
                    if(m.find(mat[x.first][i])==m.end()){
                        q.push({mat[x.first][i],x.first});
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        // cout<<"Map size"<<endl;
        // cout<<m.size();
        if(m.size()!=n){
            // cout<<"HI";
            return false;
        }
        return true;
    }
};