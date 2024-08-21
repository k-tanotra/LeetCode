class Solution {
public:
    void print( vector<int> &dp){
        for(int i=0;i<dp.size();i++)
            cout<<dp[i]<<" ";
        cout<<endl;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
      vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j] = j-i;
            }
        }
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            for(int j=0;j<=x;j++){
                for(int k=y;k<n;k++){
                    dp[j][k] = min(dp[j][k],dp[j][x] + 1 + dp[y][k]);
                }
            }
            ans.push_back(dp[0][n-1]);
        }
        return ans;
    }
};