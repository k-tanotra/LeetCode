class Solution {
public:
    /*
    int cal(int idx,vector<int>& dp,int k,vector<int>& energy){
        if(dp[idx]!=INT_MIN)
            return dp[idx];
        int score = 0;
        for(int i=idx;i<energy.size();i+=k){
            score += energy[i];
        }
        dp[idx] = max(dp[idx],score);
        return dp[idx];
    }
    int rec(vector<int>& energy,vector<int>& dp,int k){
        int mx = INT_MIN;
        for(int i=dp.size()-1;i>=0;i--){
            mx = max(mx,cal(i,dp,k,energy));
        }
        return mx;
    }*/
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(),INT_MIN);
        int n = energy.size();
        int mx = INT_MIN;
        for(int i=energy.size()-1;i>=0;i--){
            int score = energy[i];
            if(i+k<n){
                score += dp[i+k];
            }
            dp[i] = score;
            mx = max(mx,dp[i]);
        }
        return mx;
        //return rec(energy,dp,k);
    }
};