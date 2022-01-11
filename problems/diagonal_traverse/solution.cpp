class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size()-1;
        int n = mat[0].size()-1;
        int startRow = 0,startCol = 0,oppRow = 0,oppCol = 0;
        int i,j;
        bool flip = true;
        while(startCol<=n){
            if(flip){
                i = startRow;
                j = startCol;
                while(i>=0 && j<=n){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            else{
                i = oppRow;
                j = oppCol;
                 while(j>=0 && i<=m){
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
            startRow!=m ? startRow++ : startCol++;
            oppCol!=n ?  oppCol++ : oppRow++;
            flip = !flip;
        }
        return ans;
    }
};