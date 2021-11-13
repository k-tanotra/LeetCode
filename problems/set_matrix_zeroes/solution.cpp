class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int lr = false;
        int rc = false;
        for(int i=0;i<col;i++){
            if(!matrix[row-1][i]){
                lr = true;
                break;
            }
        }
        
        for(int i=0;i<row;i++){
            if(!matrix[i][col-1]){
                rc = true;
                break;
            }
        }
        
        
        for(int i=0;i<row-1;i++){
            for(int j=0;j<col-1;j++){
                if(!matrix[i][j]){
                    matrix[row-1][j] = 0;
                    matrix[i][col-1] = 0;
                }
            }
        }
        
        for(int i=0;i<col-1;i++){
            if(!matrix[row-1][i]){
                for(int j=0;j<row-1;j++){
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i=0;i<row-1;i++){
            if(!matrix[i][col-1]){
                for(int j=0;j<col-1;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(lr){
            for(int j=0;j<col;j++){
                matrix[row-1][j] = 0;
            }
        }
        
        if(rc){
            for(int j=0;j<row;j++){
                matrix[j][col-1] = 0;
            }
        }
    }
};