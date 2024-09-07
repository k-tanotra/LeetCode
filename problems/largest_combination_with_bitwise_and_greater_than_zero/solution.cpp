class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        vector<vector<int>> dp(24);
        int maxAns = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<24;j++){
                if((1<<j) & candidates[i]){
                    dp[j].push_back(candidates[i]);
                }
            }
        }
        for(int i=0;i<dp.size();i++){
            int x = dp[i].size();
            maxAns = max(maxAns,x);
        }
        return maxAns;
    }
};