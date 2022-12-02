class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> rn(grid.size(),0);
        vector<int> cn(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    rn[i] +=1;
                    if(rn[i]>=2){
                        break;
                    }
                }
            }
        }
        
        for(int j=0;j<grid[0].size();j++){
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==1){
                    cn[j] +=1;
                    if(cn[j]>=2){
                        break;
                    }
                }
            }
        }
        
        int tot = 0;
        int x = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    tot += 1;
                    if(rn[i]==1 && cn[j]==1){
                        x+=1;
                    }
                }
            }
        }
        /*
        for(int i=0;i<rn.size();i++){
            cout<<rn[i]<<endl;
        }
        cout<<"HELL"<<endl;
        for(int i=0;i<cn.size();i++){
            cout<<cn[i]<<endl;
        }
        */
        return tot-x;
    }
};