class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        //vector<vector<int>> adjList(n);
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            m[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(m.find(i)==m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};