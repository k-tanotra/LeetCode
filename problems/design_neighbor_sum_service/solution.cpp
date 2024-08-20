class NeighborSum {
public:
    unordered_map<int,int> m;
    vector<vector<int>> g;
    int n;
    bool isValid(int x,int y){
        if(x<n && y<n && x>=0 && y>=0){
            return true;
        }
        return false;
    }
    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[g[i][j]] = 10*i+j;
            }
        }
    }
    
    int adjacentSum(int value) {
        int x = m[value]/10;
        int y = m[value]%10;
        int sum = 0;
        if(isValid(x+1,y)){
            sum+= g[x+1][y];
        }
        if(isValid(x-1,y)){
            sum+= g[x-1][y];
        }
        if(isValid(x,y+1)){
            sum+= g[x][y+1];
        }
        if(isValid(x,y-1)){
            sum+= g[x][y-1];
        }
        return sum;
        
    }
    
    int diagonalSum(int value) {
        int x = m[value]/10;
        int y = m[value]%10;
        int sum = 0;
        if(isValid(x+1,y+1)){
            sum+= g[x+1][y+1];
        }
        if(isValid(x-1,y-1)){
            sum+= g[x-1][y-1];
        }
        if(isValid(x-1,y+1)){
            sum+= g[x-1][y+1];
        }
        if(isValid(x+1,y-1)){
            sum+= g[x+1][y-1];
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */