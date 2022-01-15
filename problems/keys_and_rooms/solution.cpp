class Solution {
public:
    //vector<int> visitedTrack;
    void rec(vector<vector<int>>& rooms,int idx,vector<bool> &visited){
        visited[idx] = true;
        //visitedTrack[idx] = true;
        //cout<<idx<<endl;
        for(int i=0;i<rooms[idx].size();i++){
            int x = rooms[idx][i];
            if(!visited[x])
                rec(rooms,x,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false); 
        //visitedTrack.resize(n,false);
        rec(rooms,0,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};