class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<vector<int>>> yPoints(101);
        for(int i=0; i<rectangles.size(); i++){
            yPoints[rectangles[i][1]].push_back(rectangles[i]);
        }
        for(int i=0; i<yPoints.size(); i++){
            sort(yPoints[i].begin(), yPoints[i].end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });
        }

        vector<int> res;
        for(int i=0; i<points.size(); i++){
            int cnt = 0;
            for(int j=points[i][1]; j<=100; j++){
                if(!yPoints[j].empty()){
                    auto itr = lower_bound(yPoints[j].begin(), yPoints[j].end(), points[i][0], 
                    [](const vector<int>& rect, int x) {
                        return rect[0] < x;
                    });
                    cnt += yPoints[j].size() - (itr - yPoints[j].begin());
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};