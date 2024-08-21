class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        set<int>cities;
        for(int i=0;i<n;i++){
            cities.insert(i);
        }
        for(int i=0;i<queries.size();i++){
            auto lo = cities.lower_bound(queries[i][0]+1);
            auto hi = cities.lower_bound(queries[i][1]);
            cities.erase(lo,hi);
            ans.push_back(cities.size()-1);
        }
        return ans;
    }
};