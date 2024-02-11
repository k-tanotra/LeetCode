class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& m) {
        vector<vector<int>>& matrix = m;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        for(int i=0;i<COLS;i++){
            int mx = -2;
            for(int j=0;j<ROWS;j++){
                mx = max(mx,matrix[j][i]);
            }
            for(int j=0;j<ROWS;j++){
                if(matrix[j][i]==-1)
                    matrix[j][i] = mx;
            }
        }
        return matrix;
    }
};