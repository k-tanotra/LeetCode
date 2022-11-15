class Solution {
public:
    
    int rec(int sum,vector<vector<int>> &dp,int left,int right,vector<int> &stones){
        
        if(left>right || right<0 || left>stones.size()){
            return 0;
        }
        
        if(dp[left][right]==INT_MIN){
            dp[left][right] =  max(sum - stones[left] -rec(sum-stones[left],dp,left+1,right,stones),
                                   sum - stones[right] -rec(sum-stones[right],dp,left,right-1,stones));
        }
        return dp[left][right];
    }
    int stoneGameVII(vector<int>& stones) {
        int sum =0;
        for(int i=0;i<stones.size();i++){
            sum += stones[i];
        }
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),INT_MIN));
        int left = 0;
        int right = stones.size()-1;
        return rec(sum,dp,left,right,stones);
      
    }
};