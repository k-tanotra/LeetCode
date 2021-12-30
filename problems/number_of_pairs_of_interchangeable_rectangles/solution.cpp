class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans=0;
        unordered_map<double,long long> m;
        for(int i=0;i<rectangles.size();i++){
            double k = (double)rectangles[i][0]/(double)rectangles[i][1];
            if(m.find(k)==m.end()){
                m.insert({k,1});
            }
            else{
                m[k]++;
            }
        }
        for(auto itr=m.begin();itr!=m.end();itr++){
            //cout<<itr->first<<" "<<itr->second<<endl;
            if(itr->second>=2){
                if(itr->second%2==0){
                    ans+= (itr->second-1)*((itr->second)/2);
                }
                else{
                    ans+= (itr->second)*((itr->second-1)/2);
                }
            }
        }
        
        
        return ans;
    }
};