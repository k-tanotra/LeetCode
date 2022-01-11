class Solution {
public:
    int genHash(int x,int y){
        return 4001*x + y;
    }
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> m;
        for(int i=0;i<points.size();i++){
            m.insert(genHash(points[i][0],points[i][1]));
        }
        
        int area = INT_MAX;
        for(int i=0;i<points.size();i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1;j<points.size();j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1!=x2 && y1!=y2 && m.find(genHash(x1,y2))!=m.end()  && m.find(genHash(x2,y1))!=m.end()){
                    area = min(area,abs(x1-x2)*abs(y1-y2));
                }
            }
        }
        
        return area==INT_MAX ? 0:area;
    }
};