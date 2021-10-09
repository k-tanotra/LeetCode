class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rows = accounts.size();
        int col = accounts[0].size();
        int ans = -1;
        for(int i=0;i<rows;i++){
            int sum = 0;
            for(int j=0;j<col;j++){
                sum = sum + accounts[i][j];
            } 
            ans = max(ans,sum);
        }
        return ans;
    }
};