class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,int row,int col){
        grid[i][j] = 'f';
        if(i+1<row  && grid[i+1][j]!='f' && grid[i+1][j]!='0' ){
             dfs(i+1,j,grid,row,col);
        }
        if(i-1>=0 && grid[i-1][j]!='0' && grid[i-1][j]!='f'){
             dfs(i-1,j,grid,row,col);
        }
        if(j+1<col && grid[i][j+1]!='0' && grid[i][j+1]!='f'){
             dfs(i,j+1,grid,row,col);
        }
        if(j-1>=0 && grid[i][j-1]!='0' && grid[i][j-1]!='f'){
             dfs(i,j-1,grid,row,col);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!='f' && grid[i][j]!='0'){
                    dfs(i,j,grid,row,col);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};