class Solution {
public:
    int findParent(int x,vector<int> &uf){
        while(x!=uf[x]){
            x = uf[x];
        }
        return x;
    }
    void print(vector<int> &uf){
        for(int i=0;i<uf.size();i++){
            cout<<uf[i]<<" ";
        }
        cout<<endl;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<int> uf(n,0);
        for(int i=0;i<uf.size();i++){
            uf[i]=i;
        }
        for(int i=0;i<connections.size();i++){
            int x = findParent(connections[i][0],uf);
            int y = findParent(connections[i][1],uf);
            if(x!=y){
                uf[x] = y;
            }
        }
        //print(uf);
        int count = 0;
        for(int i=0;i<uf.size();i++){
            if(uf[i]==i){
                count++;
            }
        }
        return count-1;
        //union find

        //dfs number of islands
    }
};