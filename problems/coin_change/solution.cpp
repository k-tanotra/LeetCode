class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++){
            int mn = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i){
                    break;
                }
                // cout<<coins[j]<<" "<<i<<endl;
                if(dp[i-coins[j]]!=-1)
                    mn = min(mn,1+dp[i-coins[j]]);
            }
            mn==INT_MAX ? dp[i] = -1: dp[i] = mn;
        }
        // for(int i=0;i<dp.size();i++){
        //     cout<<dp[i]<<endl;
        // }
        return dp[amount];
    }
};