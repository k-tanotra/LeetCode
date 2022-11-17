class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int tot = 0;
            for(int j=0;j<accounts[i].size();j++){
                tot += accounts[i][j];
            }
            mx = max(tot,mx);
        }
        
        return mx;
    }
};