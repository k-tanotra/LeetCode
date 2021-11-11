class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int len = nums.size();
        // vector<bool> dp(len,false);
        // dp[0] = true;
        // int cnt = 0;
        // for(int i=0;i<len;i++){
        //     if(dp[i] || cnt>0){
        //         nums[i] + i < len ? dp[i+nums[i]] = true : dp[len-1] = true;
        //         cnt = max(nums[i],cnt);
        //     }
        //     cnt--;
        // }
        // return dp[len-1];
        
        //Optimize version
        int len = nums.size();
        int cnt = 0;
        int i = 0;
        for(i=0;i<len && i<=cnt;i++){
            cnt = max(i+nums[i],cnt);
        }
        
        return i==len;
    }
};