class Solution {
public:
    int calScore(vector<vector<int>> &grid){
        int row = grid.size();
        int col = grid[0].size();
        int score = 0;

        for(int i=0;i<row;i++){
            int two = 1;
            int bn = 0;
            for(int j=col-1;j>=0;j--){
                bn += grid[i][j]*two;
                two *= 2;
            }
            score += bn;
        }
        return score;
    }

    void flipCol(vector<vector<int>> &grid,int col){
        int row = grid.size();
        for(int i=0;i<row;i++){
            grid[i][col] = !grid[i][col];
        }
    }

    void flipRow(vector<vector<int>> &grid,int row){
        int col = grid[0].size();
        for(int i=0;i<col;i++){
            grid[row][i] = !grid[row][i];
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
       
        for(int i=0;i<col;i++){
            int ones = 0;
            int zeros = 0;
            //cout<<"HELLO"<<endl;
            for(int j=0;j<row;j++){
                if(i==0){
                    if(grid[j][i]==0){
                        //flip row
                        flipRow(grid,j);
                    }
                }
                else{
                    if(grid[j][i]==1){
                        ones++;
                    }
                    else{
                        zeros++;
                    }
                }
            }
            if(i!=0){
                if(zeros>ones){
                    //flip col
                    flipCol(grid,i);
                }
            }
        }
        //cout<<"HELLO"<<endl;
        int score = calScore(grid);
        return score;
    }
};