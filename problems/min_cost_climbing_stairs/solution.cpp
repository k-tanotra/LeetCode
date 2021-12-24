class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = cost[0];
        for(int i=1;i<n;i++){
            dp[i+1] = cost[i]+min(dp[i],dp[i-1]);
        }
        /*
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        */
        return min(dp[n],dp[n-1]);
    }
};