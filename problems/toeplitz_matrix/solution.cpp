class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int start = 0;
        int cols = matrix[0].size();
        int rows = matrix.size();
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i-1][j-1]!=matrix[i][j])
                    return false;
            }
        }
        return true;
    }
};