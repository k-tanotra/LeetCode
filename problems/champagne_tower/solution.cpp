class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100,vector<double> (100,0.0));
        dp[0][0] = poured;
        for(int i=1;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                double x = dp[i-1][j]-1 >=0 ? dp[i-1][j]-1 : 0.00000;
                dp[i][j] = (x*1.00000)/2;
                if(j>0){
                    x = dp[i-1][j-1]-1 >= 0 ? dp[i-1][j-1]-1: 0.00000;
                    dp[i][j] += (x*1.00000)/2;
                }
            }
        }
        return dp[query_row][query_glass]>1 ? 1.00000 : dp[query_row][query_glass];
    }
};