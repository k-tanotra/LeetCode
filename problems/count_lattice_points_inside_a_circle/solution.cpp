class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int Xmax = circles[0][0]+circles[0][2];
        int Xmin = circles[0][0]-circles[0][2];
        int Ymax = circles[0][1]+circles[0][2];
        int Ymin = circles[0][1]-circles[0][2];
        for(int i=1;i<circles.size();i++){
            Xmax = max(Xmax,circles[i][0]+circles[i][2]);
            Xmin = min(Xmin,circles[i][0]-circles[i][2]);
            Ymax = max(Ymax,circles[i][1]+circles[i][2]);
            Ymin = min(Ymin,circles[i][1]-circles[i][2]);
        }
        int cnt = 0;
        for(int i=Xmin;i<=Xmax;i++){
            for(int j=Ymin;j<=Ymax;j++){
                int c = 0;
                for(int k=0;k<circles.size();k++){
                    if((i-circles[k][0])*(i-circles[k][0]) + (j-circles[k][1])*(j-circles[k][1]) <= circles[k][2]*circles[k][2]){
                        c++;
                    }
                }
                if(c>=1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};