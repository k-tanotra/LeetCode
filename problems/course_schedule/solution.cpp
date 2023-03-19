class Solution {
public:
    void print(vector<bool> &vis){
        for(int i=0;i<vis.size();i++){
            cout<<vis[i]<<" ";
        }
        cout<<"\n";
    }
    bool dfs(int idx,unordered_map<int,vector<int>> &m,vector<int> &vis){
       //cout<<idx<<endl;
      // print(vis);
       if(vis[idx]==1){
           return false;
       }
       if(vis[idx]==2){
           return true;
       }
       vis[idx] = 1;
       bool ways = true;
       for(int i=0;i<m[idx].size();i++){
           ways = ways && dfs(m[idx][i],m,vis);
           if(ways==false){
               vis[idx] = 0;
               return ways;
           }
       }
       vis[idx] = 2;
       return ways;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,false);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<prerequisites.size();i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                if(!dfs(i,m,vis)){
                    return false;
                }
            }
        }

        return true;
    }
};