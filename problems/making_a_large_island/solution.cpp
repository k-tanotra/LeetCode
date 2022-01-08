class Solution {
public:
    int n;
    unordered_map<int,int> m;
    bool canMove(int x,int y){
        if(x<0 || x>=n || y<0 || y>=n){
            return false;
        }
        return true;
    }
    void dfs(int x,int y,int color,vector<vector<int>> &grid,int &size){
        if(!canMove(x,y)){
            return;
        }
        size++;
        grid[x][y] = color;
        if(canMove(x+1,y) && grid[x+1][y]==1){
            dfs(x+1,y,color,grid,size);
        }
         if(canMove(x-1,y) && grid[x-1][y]==1){
            dfs(x-1,y,color,grid,size);
        }
         if(canMove(x,y+1) && grid[x][y+1]==1){
            dfs(x,y+1,color,grid,size);
        }
        if(canMove(x,y-1) && grid[x][y-1]==1){
            dfs(x,y-1,color,grid,size);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int color = 2;
        n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size = 0;
                    dfs(i,j,color,grid,size);
                    m[color] = size;
                    color++;
                }
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<endl;
        */
        int ans = 0;
        for(auto itr=m.begin();itr!=m.end();itr++){
            ans = max(ans,itr->second);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int cur = 0;
                    unordered_set<int> st;
                    if(canMove(i+1,j) && grid[i+1][j]>1 && st.find(grid[i+1][j])==st.end()){
                            cur+=m[grid[i+1][j]];
                            st.insert({grid[i+1][j]});
                    }
                    if(canMove(i-1,j) && grid[i-1][j]>1 && st.find(grid[i-1][j])==st.end()){
                            cur+= m[grid[i-1][j]];
                            st.insert({grid[i-1][j]});
                    }
                     if(canMove(i,j+1) && grid[i][j+1]>1 && st.find(grid[i][j+1])==st.end()){
                            cur+= m[grid[i][j+1]];
                            st.insert({grid[i][j+1]});
                    }
                    if(canMove(i,j-1) && grid[i][j-1]>1 && st.find(grid[i][j-1])==st.end()){
                            cur+= m[grid[i][j-1]];
                            st.insert({grid[i][j-1]});
                    }
                    
                    ans = max(ans,cur+1);
                }
            }
        }
        
        return ans;
    }
};