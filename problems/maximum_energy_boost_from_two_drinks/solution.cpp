class Solution {
public:
    long long maxEnergy(vector<int>& A,vector<int>& B,int cur,int hour,int n,vector<vector<long long>> &dp){
        if(hour>=n){
            return 0;
        }
        if(dp[cur][hour]!=-1){
            return dp[cur][hour];
        }
        if(cur==0){
            dp[cur][hour] = A[hour] + max(maxEnergy(A,B,cur,hour+1,n,dp),maxEnergy(A,B,1,hour+2,n,dp));
        }
        else{
            dp[cur][hour] = B[hour] + max(maxEnergy(A,B,cur,hour+1,n,dp),maxEnergy(A,B,0,hour+2,n,dp));
        }
        
        return dp[cur][hour];
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(2,vector<long long>(n,-1));
        long long ans = max(maxEnergy(energyDrinkA,energyDrinkB,0,0,n,dp),maxEnergy(energyDrinkA,energyDrinkB,1,0,n,dp));
        return ans;
    }
};