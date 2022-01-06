class Solution {
public:
    int n;
    unordered_map<int,vector<pair<int,int>>> m;
    bool canMove(int x,int y){
        if(x<0 || x>=n || y<0 || y>=n){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& grid,int x,int y){
        if(!canMove(x,y) || grid[x][y]==2){
            return;
        }
        grid[x][y] = 2;
        if(canMove(x+1,y) && grid[x+1][y]==1){
            dfs(grid,x+1,y);
        }
        if(canMove(x-1,y) && grid[x-1][y]==1){
            dfs(grid,x-1,y);
        }
        if(canMove(x,y+1) && grid[x][y+1]==1){
            dfs(grid,x,y+1);
        }
        if(canMove(x,y-1) && grid[x][y-1]==1){
            dfs(grid,x,y-1);
        }
    }
    
    void dfs2(vector<vector<int>>& grid,int x,int y,int color){
        if(!canMove(x,y) || grid[x][y]==color){
            return;
        }
        grid[x][y] = color;
        if(m.find(color)==m.end()){
            vector<pair<int,int>> v;
            v.push_back({x,y});
            m.insert({color,v});
        }
        else{
            m[color].push_back({x,y});
        }
        
        if(canMove(x+1,y) && grid[x+1][y]==1){
            dfs2(grid,x+1,y,color);
        }
        if(canMove(x-1,y) && grid[x-1][y]==1){
            dfs2(grid,x-1,y,color);
        }
        if(canMove(x,y+1) && grid[x][y+1]==1){
            dfs2(grid,x,y+1,color);
        }
        if(canMove(x,y-1) && grid[x][y-1]==1){
            dfs2(grid,x,y-1,color);
        }
    }
        
    int shortestBridge(vector<vector<int>>& grid) {

        // method 1 DFS + BFS
        //starts here kanishk 
        /*
        n = grid.size(); 
        bool flag = true;
        for(int i=0;i<n && flag;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                   dfs(grid,i,j);
                   flag = false;
                   break;
               }
           }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        
        bool found = false;
        int start = 2;
        int ans;
        while(!found){
            for(int i=0;i<n && !found;i++){
                for(int j=0;j<n && !found;j++){
                    if(grid[i][j]==start){
                        if((canMove(i+1,j) && grid[i+1][j]==1) || (canMove(i-1,j) && grid[i-1][j]==1) || (canMove(i,j+1) && grid[i][j+1]==1) || (canMove(i,j-1) && grid[i][j-1]==1)){
                            ans = start;
                            found = true;
                        }
                        if(canMove(i+1,j) && grid[i+1][j]==0){
                            grid[i+1][j] = start+1;
                        }
                        if(canMove(i-1,j) && grid[i-1][j]==0){
                            grid[i-1][j] = start+1;
                        }
                        if(canMove(i,j+1) && grid[i][j+1]==0){
                            grid[i][j+1] = start+1;
                        }
                        if(canMove(i,j-1) && grid[i][j-1]==0){
                            grid[i][j-1] = start+1;
                        }
                    }
                }
            }
            start++;
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        return ans-2;
        // ends here kanishk
        */
        // method 2 Distance 
        
        n = grid.size(); 
        int color = 2;
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                   dfs2(grid,i,j,color);
                   color++;
               }
           }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        
        cout<<"\n";
        for(auto itr=m.begin();itr!=m.end();itr++){
            cout<<itr->first<<endl;
            for(int i=0;i<itr->second.size();i++){
                cout<<itr->second[i].first<<" "<<itr->second[i].second<<" ** ";
            }
            cout<<"\n";
        }
        */
        
        int ans = INT_MAX;
        vector<pair<int,int>> vec1 = m[2];
        vector<pair<int,int>> vec2 = m[3];
        
        for(int i=0;i<vec1.size();i++){
            for(int j=0;j<vec2.size();j++){
                ans = min(abs(vec1[i].first-vec2[j].first) + abs(vec1[i].second-vec2[j].second)-1,ans);
                if(ans==1){
                    return ans;
                }
            }
        }
        
        
        return ans;
    }
};