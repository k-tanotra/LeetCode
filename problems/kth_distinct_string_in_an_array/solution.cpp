class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,vector<int>> m;
        for(int i=0;i<arr.size();i++){
           if(m.find(arr[i])==m.end()){
               vector<int> v;
               v.push_back(1);
               v.push_back(i);
               m.insert({arr[i],v});
           }
           else{
               m[arr[i]][0]++;
           }
        }
        string a="";
        int c = 0;
        set<pair<int,string>> ans;
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr->second[0]==1){
                c++;
                ans.insert(make_pair(itr->second[1],itr->first));
            }
        }
        
        if(c<k){
            return "";
        }
        auto it = ans.begin();
        advance(it,k-1);
        return it->second;
    }
};