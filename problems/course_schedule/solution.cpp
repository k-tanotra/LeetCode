class Solution {
public:
    unordered_map<int,vector<int>> m;
    bool dfs(vector<bool> &visited,int cur,set<pair<int,int>> &t){
        if(visited[cur]){
            return false;
        }
        vector<int> s = m[cur];
        for(int i=0;i<s.size();i++){
            visited[cur]=true;
            if(t.find({cur,s[i]})==t.end()){
                if(!dfs(visited,s[i],t)){
                    return false;
                }
            }
            visited[cur]=false;
            t.insert({cur,s[i]});
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        m.clear();
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            if(m.find(prerequisites[i][0])==m.end()){
                vector<int> x;
                x.push_back(prerequisites[i][1]);
                m.insert({prerequisites[i][0],x});
            }
            else{
                m[prerequisites[i][0]].push_back(prerequisites[i][1]);
            }
        }
        vector<bool> visited(numCourses,false);
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            visited[prerequisites[i][0]]=true;
            if(s.find({prerequisites[i][0],prerequisites[i][1]})==s.end()){
                if(!dfs(visited,prerequisites[i][1],s)){
                    return false;
                }
            }
            s.insert({prerequisites[i][0],prerequisites[i][1]});
            visited[prerequisites[i][0]]=false;
        }
        return true;
    }
};