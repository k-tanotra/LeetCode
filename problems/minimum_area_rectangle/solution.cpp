class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_set<int> s;
        
        for(int i=0;i<points.size();i++){
            s.insert(points[i][0] + points[i][1]*40001);
        }
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]!=points[j][0] && points[i][1]!=points[j][1] && s.find(points[i][0] + points[j][1]*40001)!=s.end() && s.find(points[j][0] + points[i][1]*40001)!=s.end()){
                    ans = min(ans,abs(points[j][0]-points[i][0])*abs(points[j][1]-points[i][1]));
                }
            }
        }
        
        return ans==INT_MAX ? 0 : ans;
    }
};