class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> dp(n,0);
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            dp[i] = max(ans,values[i]+i);
            ans = max(dp[i],ans);
        }
        /*
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }*/
        vector<int> dp2(n,0);
        ans = INT_MIN;
        for(int i=n-1;i>=0;i--){
            dp2[i] = max(ans,values[i]-i);
            ans = max(dp2[i],ans);
        }
        
        ans= INT_MIN;
        for(int i=0;i<n-1;i++){
            ans = max(dp[i]+dp2[i+1],ans);
        }
        /*
        for(int i=0;i<n;i++){
            cout<<dp2[i]<<" ";
        }
        */
        return ans;
    }
 };