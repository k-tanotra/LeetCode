class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        map<int,int> m;
        int unq = 0;
        for(int i=0;i<candies.size();i++){
            if(m.find(candies[i])==m.end()){
                m.insert({candies[i],1});
                unq++;
            }
            else{
                m[candies[i]]++;
            }
        }
        int cur = unq;
        for(int i=0;i<k;i++){
            m[candies[i]]--;
            if(m[candies[i]]==0){
                cur--;
            }
        }
        int ans = cur;
        for(int i=1;i<candies.size()-k+1;i++){
            //cout<<"in"<<endl;
            //cout<<i<<" "<<cur<<endl;
            if(m[candies[i-1]]==0){
                cur++;
            }
            //cout<<i<<" "<<cur<<" "<<candies[i+k]<<endl;
            m[candies[i-1]]++;
            m[candies[i+k-1]]--;
            if(m[candies[i+k-1]]==0){
                cur--;
            }
            //cout<<i<<" "<<cur<<endl;
            ans = max(cur,ans);
        }
                 
        return ans;
    }
};