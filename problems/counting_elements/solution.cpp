class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])==m.end()){
                m.insert({arr[i],1});
            }
            else{
                m[arr[i]]++;
            }
        }
        
        int ans=0;
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(m.find(itr->first+1)!=m.end()){
                ans+=itr->second;
            }
        }
        /*
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i]+1)!=m.end()){
                ans++;
            }
        }
        */
        
        return ans;
    }
};