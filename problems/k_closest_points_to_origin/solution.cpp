class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        set< pair<long long,vector<int>> > s;
        vector<vector<int> > ans;
        int len = points.size();
        
        for(int i=0;i<len;i++){
            s.insert(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1] , points[i]) );
        }
        int j = 0;
        for (auto itr = s.begin(); itr != s.end() && j<k; itr++){
            ans.push_back((*itr).second);
            j++;
        }
        return ans;
    }
};