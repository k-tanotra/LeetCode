class Solution {
public:
    struct point{
        int x;
        int y;
    };
    vector<vector<int>> v;
    map<pair<int,int>,int> points;
    unordered_map<int,int> colorArea;
    bool canMove(pair<int,int> p){
        if(p.first<0 || p.second<0 || p.first>=v.size() || p.second>=v[0].size()){
            return false;
        }
        return true;
    }
    void dfs(int color,int &area,pair<int,int> z){
        ///cout<<"x--> "<<z.first<<" y--> "<<z.second<<" val--> "<<v[z.first][z.second]<<" Area-->"<<area<<endl;
        points[z] = color;
        pair<int,int> up = {z.first-1,z.second};
        pair<int,int> down = {z.first+1,z.second};
        pair<int,int> left = {z.first,z.second-1};
        pair<int,int> right = {z.first,z.second+1};
        area+=1;
        if(canMove(up) && v[up.first][up.second]==1 && points.find(up)==points.end()){
            dfs(color,area,up);
        }
        if(canMove(down) && v[down.first][down.second]==1 && points.find(down)==points.end()){
            dfs(color,area,down);
        }
        if(canMove(left) && v[left.first][left.second]==1 && points.find(left)==points.end()){
            dfs(color,area,left);
        }
        if(canMove(right) && v[right.first][right.second]==1 && points.find(right)==points.end()){
            dfs(color,area,right);
        }
    }
    void calArea(){
        int color = 1;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                pair<int,int> z = {i,j};
                if(v[i][j]==1 && points.find(z)==points.end()){
                    int area = 0;
                    dfs(color,area,z);
                    colorArea[color] = area;
                    color++;
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        v = grid;
        calArea();
        int ans = INT_MIN;
       // cout<<endl;
        
        for(auto itr=colorArea.begin(); itr!=colorArea.end(); itr++){
            //cout<<itr->first<<" "<<itr->second<<endl;
            ans=max(ans,itr->second);
        }
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]==0){
                    int temp = 0;
                    pair<int,int> z = {i,j};
                    set<int> col;
                    pair<int,int> up = {z.first-1,z.second};
                    pair<int,int> down = {z.first+1,z.second};
                    pair<int,int> left = {z.first,z.second-1};
                    pair<int,int> right = {z.first,z.second+1};
                    if(points.find(up)!=points.end() && col.find(points[up])==col.end()){
                        temp+= colorArea[points[up]];
                        col.insert(points[up]);
                    }
                    if(points.find(down)!=points.end() && col.find(points[down])==col.end()){
                        temp+= colorArea[points[down]];
                        col.insert(points[down]);
                    }
                    if(points.find(right)!=points.end() && col.find(points[right])==col.end()){
                        temp+= colorArea[points[right]];
                        col.insert(points[right]);
                    }
                    if(points.find(left)!=points.end() && col.find(points[left])==col.end()){
                        temp+= colorArea[points[left]];
                        col.insert(points[left]);
                    }
                    
                    ans = max(ans,temp+1);
                }
            }
        }
        return ans;
    }
};