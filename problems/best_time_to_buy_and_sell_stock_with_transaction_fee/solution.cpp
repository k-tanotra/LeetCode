class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int f;
    int rec(vector<int>& prices,int idx,int status){
        if(idx>=n){
           // cout<<" found end--> "<<cur<<endl;
            return 0;
        }
       // cout<<prices[idx]<<(status?" Sell ":" Buy ")<<cur<<endl;
        if(dp[status][idx]==INT_MIN){
            if(status)
              dp[status][idx] = max(rec(prices,idx+1,0)+prices[idx]-f,rec(prices,idx+1,1));
            else
              dp[status][idx] = max(rec(prices,idx+1,1)-prices[idx],rec(prices,idx+1,0));
        }
        return dp[status][idx];
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        f = fee;
        dp.resize(2,vector<int>(n,INT_MIN));
        return rec(prices,0,0);
    }
};