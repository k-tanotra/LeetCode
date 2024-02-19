class Solution {
public:
    int calculate(vector<int>& nums,int start,int end,vector<vector<int>> &dp,int score){
        if(end-start<1){
            return 0;
        }
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        int a = 0;
        int b = 0;
        int c = 0;
        
        if(score==-1 || nums[start]+nums[start+1]==score)
            a = 1 + calculate(nums,start+2,end,dp,nums[start]+nums[start+1]);
        if(score==-1 || nums[end]+nums[end-1]==score)
            b = 1 + calculate(nums,start,end-2,dp,nums[end]+nums[end-1]);
        if(score==-1 || nums[start]+nums[end]==score)
            c = 1 + calculate(nums,start+1,end-1,dp,nums[start]+nums[end]);
        
        dp[start][end] = max(a,max(b,c));
        
        return dp[start][end];
    }
    int maxOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return calculate(nums,0,nums.size()-1,dp,-1);
    }
};