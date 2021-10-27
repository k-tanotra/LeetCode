class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        int n = edges.size();
        for(int i=0;i<n;i++){
            if(m.find(edges[i][0])==m.end()){
                m.insert({edges[i][0],1});
            }
            else{
                m[edges[i][0]]++;
            }
            
            if(m.find(edges[i][1])==m.end()){
                m.insert({edges[i][1],1});
            }
            else{
                m[edges[i][1]]++;
            }
        }
        int max = INT_MIN;
        int center;
        for(auto itr=m.begin();itr!=m.end();itr++){
            // cout<<itr->first<<" "<<itr->second<<endl;
            if(itr->second > max){
                max = itr->second;
                center = itr->first;
            }
        }
        
        return center;
    }
};