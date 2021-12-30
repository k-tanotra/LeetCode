class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r1 = 0;
        int c1 = 0;
        int r2 = 0;
        int c2 = mat[0].size()-1;
        int sum = 0;
        while(r1<mat.size()){
            sum += mat[r1][c1];
            sum += mat[r2][c2];
            if(c1==c2){
                sum-= mat[r2][c2];
            }
            r1++;
            c1++;
            r2++;
            c2--;
        }
        
        return sum;
    }
};