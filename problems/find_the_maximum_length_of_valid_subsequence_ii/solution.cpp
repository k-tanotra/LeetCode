class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int mx = 0;
        vector<vector<int>> dp(k);
        for(int i=0;i<nums.size();i++){
            dp[nums[i]%k].push_back(i);
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp.size();j++){
                int cnt = 0;
                if(i==j){
                    cnt = dp[i].size();
                }
                else{
                     int p1 = 0;
                     int p2 = 0;
                     bool toggle = false;
                     int f = -1;
                     while(p1<dp[i].size() && p2<dp[j].size()){
                        if(!toggle){
                            f = dp[i][p1];
                            p2 = upper_bound(dp[j].begin(),dp[j].end(),f) - dp[j].begin();
                            toggle = !toggle;
                            cnt++;
                        }
                        else{
                            f = dp[j][p2];
                            p1 = upper_bound(dp[i].begin(),dp[i].end(),f) - dp[i].begin();
                            toggle = !toggle;
                            cnt++;
                        }
                     }
                     /*
                     if(p1<dp[i].size()){
                         cnt++;
                     }
                     if(p2<dp[j].size()){
                        cnt++;
                     }*/
                }
                mx = max(mx,cnt);
            }
        }
       return mx;
    }
};