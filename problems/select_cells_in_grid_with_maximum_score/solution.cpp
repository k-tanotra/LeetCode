class Solution {
public:
    void print(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int bitMask(int mask,int M,int rows,int cols,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(mask==0){
            return 0;
        }
        if(dp[mask][M]!=-1){
            return dp[mask][M];
        }
        int ans = 0;
        for(int i=0;i<rows;i++){
            if(mask & (1<<i)){
                for(int j=0;j<cols;j++){
                    if(grid[i][j]<=M){
                        ans = max(ans,bitMask(mask-(1<<i),grid[i][j]-1,rows,cols,grid,dp)+grid[i][j]);
                    }
                }
            }
        }
        dp[mask][M] = ans;
        return  dp[mask][M];
    }
    int maxScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp((1<<rows),vector<int>(101,-1));
        dp[0][100] = 0;
        return bitMask((1<<rows)-1,100,rows,cols,grid,dp);
        
    }
};