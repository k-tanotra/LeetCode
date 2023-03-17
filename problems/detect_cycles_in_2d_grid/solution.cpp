class Solution {
public:
    vector<vector<char>> g;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int rd[4] = {2,3,0,1};
    bool dfs(int i,int j,int dir){
        //cout<<g[i][j]<<" "<<i<<" "<<j<<endl;
        //print(g);
        if(g[i][j]=='*')
            return true;
        char c = g[i][j];
        g[i][j] = '*';
        for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(rd[k]!=dir && x>=0 && x<g.size() && y>=0 && y<g[0].size() && (c==g[x][y] || g[x][y]=='*')){
                if(dfs(x,y,k))
                    return true;
            }
        }
        g[i][j] = '#';
        return false;
    }
    void print(vector<vector<char>> &g){
        cout<<"PRINT"<<endl;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                cout<<g[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"END"<<endl;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        g = grid;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(g[i][j]!='#' && dfs(i,j,-1))
                    return true;
                //cout<<"end"<<endl;
            }
        }
        return false;
    }
};