class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int len = towers.size();
        int temp;
        vector<int> ans;
        vector<int> dist;
        
        int max_dist,index_x,index_y;
        max_dist = -1;
        index_x = -1;
        index_y = -1;
        pair<int,int> res;
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                int signal = 0;
                for(int k=0;k<len;k++){
                    int distance = (towers[k][0] - i) * (towers[k][0] - i);
                    distance += (towers[k][1] - j)*(towers[k][1] - j);
                    if(distance <= radius*radius){
                        signal += (towers[k][2] / (1+ sqrt(distance))); 
                    }
                }
                dist.push_back(signal);
                if(signal>max_dist){
                    max_dist = signal;
                    res.first = i;
                    res.second = j;
                }
                else if(signal==max_dist){
                    res = min(res,make_pair(i,j));
                }
            }
        }
        
        ans.push_back(res.first);
        ans.push_back(res.second);
        return ans;
    }
};