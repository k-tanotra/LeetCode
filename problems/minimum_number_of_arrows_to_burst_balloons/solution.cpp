class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        if(a[1]==b[1])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int arrows = 1;
        int end = points[0][1];
        for(int i=1;i<points.size();i++){
            while(i<points.size() && points[i][0]<=end){
                i++;
            }
            if(i<points.size()){
                end = points[i][1];
                arrows++;
            }
        }
        return arrows;
    }
};