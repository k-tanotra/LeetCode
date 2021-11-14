class Solution {
public:
    bool dfs(vector<vector<char>>& board,vector<vector<bool>> &visited,string word,int idx,int row,int col,int x,int y){
        // cout<<board[x][y]<<" "<<x<<" "<<y<<endl;
        if(idx>word.length()){
            return false;
        }
        if(word[idx]!=board[x][y]){
            return false;
        }
        if(idx==word.length()-1){
            return true;
        }
        
        visited[x][y]=true;
        if(x-1>=0 && !visited[x-1][y]){
            if(dfs(board,visited,word,idx+1,row,col,x-1,y)){
                return true;
            }
        }
        if(x+1<row && !visited[x+1][y]){
            if(dfs(board,visited,word,idx+1,row,col,x+1,y)){
                return true;
            }
        }
        if(y-1>=0 && !visited[x][y-1]){
            if(dfs(board,visited,word,idx+1,row,col,x,y-1)){
                return true;
            }
        }
        if(y+1<col && !visited[x][y+1]){
            if(dfs(board,visited,word,idx+1,row,col,x,y+1)){
                return true;
            }
        }
        visited[x][y] = false;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int col = board[0].size();
        if(word.length()<=0){
            return false;
        }
        vector<vector<bool>> visited(rows,vector<bool>(col,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                visited[i][j] = true;
                if(dfs(board,visited,word,0,rows,col,i,j))
                    return true;
                visited[i][j] = false;
            }
        }
        
        return false;
    }
};