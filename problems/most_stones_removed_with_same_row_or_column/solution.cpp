class Solution {
public:
    bool isValid(int x,int y,vector<vector<int>> &visited){
        if(x>=0 && x<10001 && y>=0 && y<10001 && visited[x][y]!=-1 && visited[x][y]!=0){
            return true;
        }
        return false;
    }
    void dfs(int x,int y,vector<vector<bool>> &visited,vector<vector<int>> &stones){
        if(visited[x][y]==false){
            return;
        }
        cout<<x<<" "<<y<<endl;
        visited[x][y] = false;
        for(int i=0;i<stones.size();i++){
            if((stones[i][0]==x || stones[i][1]==y)){
                dfs(stones[i][0],stones[i][1],visited,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
       int islands = 0;
       vector<vector<bool>> visited(10001,vector<bool>(10001,false));
       for(int i=0;i<stones.size();i++){
           visited[stones[i][0]][stones[i][1]] = true;
       }
       for(int i=0;i<stones.size();i++){
           if(visited[stones[i][0]][stones[i][1]]!=false){
                dfs(stones[i][0],stones[i][1],visited,stones);
                islands++;
           }
           //cout<<"hell"<<endl;
       }
       return stones.size()-islands;
    }
};