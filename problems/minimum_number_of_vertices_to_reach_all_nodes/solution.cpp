class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> child(n,false);
        for(int i=0;i<edges.size();i++){
            child[edges[i][1]] = true;
        }
        vector<int> ans;
        for(int i=0;i<child.size();i++){
            if(!child[i])
                ans.push_back(i);
        }

        return ans;
    }
};