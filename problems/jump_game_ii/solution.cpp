class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int jumps = nums[i];
            //cout<<"JUMPS "<<jumps<<endl;
            for(int j=1;j<=jumps && j+i<n;j++){
                int x = (dp[i]==INT_MAX) ? INT_MAX : dp[i]+1;
                //cout<<x<<endl;
                dp[j+i] = min(dp[j+i],x);
            }
        }
        return dp[n-1];
    }
};

