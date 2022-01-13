class Solution {
public:
    int m;
    int n;
    bool canMove(int x,int y){
        if(x<0 || x>=m || y<0 || y>=n){
            return false;
        }
        return true;
    }
    bool dfs(int x,int y,vector<vector<char>>& board,string word,int idx){
        ///cout<<cur<<" "<<x<<" "<<y<<endl;
        if(word[idx]!=board[x][y]){
            return false;
        }
        else if(idx==word.length()-1){
            return true;
        }
        char ch = board[x][y];
        board[x][y] = '*';
        bool a,b,c,d;
        if(canMove(x+1,y)){
            a = dfs(x+1,y,board,word,idx+1);
            if(a)
                return true;
        }
        if(canMove(x-1,y)){
            b = dfs(x-1,y,board,word,idx+1);
            if(b)
                return true;
        }
        if(canMove(x,y+1)){
            c = dfs(x,y+1,board,word,idx+1);
            if(c)
                return true;
        }
        if(canMove(x,y-1)){
            d = dfs(x,y-1,board,word,idx+1);
            if(d)
                return true;
        }
        board[x][y] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j] && dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};