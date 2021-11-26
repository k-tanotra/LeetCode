class Solution {
public:
    vector<vector<int>> dp;
    int ans(vector<int> &nums){
        return max(rec(nums,0,1),rec(nums,0,0));        
    }
    int rec(vector<int> &nums,int idx,int incl){
        if(idx>=nums.size()){
            return 0;
        }
        else if(idx==0 && incl){
            if(dp[idx][incl]==-1){
                dp[idx][incl] = rec(nums,idx+2,incl)+nums[idx];
            }
            return dp[idx][incl];
        }
        else if(idx==0 && !incl){
            if(dp[idx][incl]==-1){
                dp[idx][incl] = rec(nums,idx+1,incl);
            }
            return dp[idx][incl];
        }
        else if(idx==nums.size()-1 && incl){
            dp[idx][incl] = 0;
            return dp[idx][incl];
        }
        if(dp[idx][incl]==-1){
            dp[idx][incl] = max(rec(nums,idx+2,incl)+nums[idx],rec(nums,idx+1,incl));
        }
        return dp[idx][incl];
    }
    
    int ans2(vector<int> &nums){
        return max(calc(nums,0,nums.size()-1),calc(nums,1,nums.size()));
    }
    int calc(vector<int> v,int s,int e){
        vector<int> dp(v.size()+2,0);
        for(int i=s;i<e;i++){
            dp[i+2] = max(dp[i+1],dp[i]+v[i]);
        }
        return dp[e+1];
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        if(nums.size()==1){
            return nums[0];
        }
        return ans2(nums);
    }
};