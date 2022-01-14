class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double slope;
        if((coordinates[1][0] - coordinates[0][0])==0){
            for(int i=1;i<coordinates.size();i++){
                if(coordinates[i][0]!=coordinates[0][0]){
                    return false;
                }
            }
            return true;
        }
        slope = (1.00000*(coordinates[1][1] - coordinates[0][1]))/(coordinates[1][0] - coordinates[0][0]);
        cout<<slope<<endl;
        for(int i=1;i<coordinates.size()-1;i++){
            if((1.00000*(coordinates[i+1][1] - coordinates[i][1]))/(coordinates[i+1][0] - coordinates[i][0])!=slope){
                return false;
            }
        }
        return true;
    }
};