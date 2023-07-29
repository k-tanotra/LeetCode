class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows check
        for(int i=0;i<board.size();i++){
            vector<int> count(10,0);
            //cout<<"XXXX"<<endl;
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.')
                    continue;
                count[board[i][j]-'0']++;
               // cout<<count[board[i][j]-'0']<<endl;
                if(count[board[i][j]-'0']>1){
                    //cout<<"YES"<<endl;
                    return false;
                }
            }
        }
        //col check
        for(int i=0;i<board[0].size();i++){
            vector<int> count(10,0);
            for(int j=0;j<board.size();j++){
                if(board[j][i]=='.')
                    continue;
                count[board[j][i]-'0']++;
                if(count[board[j][i]-'0']>1){
                    //cout<<"YEEHAW"<<endl;
                    return false;
                }
            }
        }
        //square check
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[0].size();j+=3){
                vector<int> count(10,0);
                for(int k=i;k<3+i;k++){
                    for(int l=j;l<3+j;l++){
                        if(board[k][l]=='.')
                            continue;
                        count[board[k][l]-'0']++;
                        if(count[board[k][l]-'0']>1){
                            //cout<<"YEEE"<<endl;
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};