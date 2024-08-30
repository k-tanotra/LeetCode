class Solution {
public:
    struct point{
        int val;
        int x;
        int y;
    };
    int maxScore(vector<vector<int>>& grid) {
        int score = INT_MIN;
        auto cmp = [](point &a,point &b){
            return a.val<b.val;
        };
        priority_queue<point,vector<point>,decltype(cmp)> pq(cmp);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                pq.push({grid[i][j],i,j});
            }
        }
        for(int i=0;i<grid.size();i++){
            auto z = pq;
            for(int j=0;j<grid[i].size();j++){
               while(!z.empty()){
                   if((z.top().x>=i && z.top().y>j) || (z.top().x>i && z.top().y>=j)){
                       score = max(score,z.top().val-grid[i][j]);
                       break;
                   }
                   z.pop();
               }
            }
        }
        /*
        while(!pq.empty()){
            cout<<pq.top().val<<" "<<pq.top().x<<" "<<pq.top().y<<" "<<endl;
            pq.pop();
        }*/
        return score;
    }
};