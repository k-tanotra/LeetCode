class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> m;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(m.find(arr[i])==m.end()){
                m.insert({arr[i],1});
            }
            else{
                m[arr[i]]++;
            }
        }
        int sz = 0;
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]!=0){
                if(m.find(arr[i]*2)!=m.end() && m[arr[i]*2]!=0){
                    sz++;
                    m[arr[i]]--;
                    m[arr[i]*2]--;
                    if(m[arr[i]*2]<0){
                        sz--;
                        m[arr[i]*2] = 0;
                    }
                }
            }
        }
        //cout<<sz<<endl;
        if(sz*2==arr.size()){
            return true;
        }
        return false;
    }
};