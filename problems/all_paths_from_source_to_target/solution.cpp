class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<vector<int>>& graph,int idx,int target,vector<int> path,vector<bool> visited){
        //cout<<idx<<endl;
        path.push_back(idx);
        if(idx==target){
            ans.push_back(path);
            return;
        }
        visited[idx] = true;
        for(int i=0;i<graph[idx].size();i++){
            int x = graph[idx][i];
            //cout<<"in--"<<graph[idx][i]<<(visited[x]?"true":"false")<<endl;
            if(!visited[x]){
                rec(graph,x,target,path,visited);
            }
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = graph.size()-1;
        vector<int> path;
        vector<bool> visited(target+1,false);
        rec(graph,0,target,path,visited);
        return ans;
    }
};