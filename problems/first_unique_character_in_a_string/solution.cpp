class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;
        for(int i=s.length()-1;i>=0;i--){
            if(m.find(s[i])==m.end()){
                m.insert({s[i],make_pair(i,1)});
            }
            else{
                m[s[i]].second++;
            }
        }
         // for(auto itr=m.begin();itr!=m.end();itr++){
         //        cout<<itr->first<<" "<<itr->second.first<<" "<<itr->second.second<<endl;
         //    }
         //    cout<<endl;
        for(auto itr=m.begin();itr!=m.end();itr++){
            //cout<<itr->first<<" "<<itr->second.first<<" "<<itr->second.second<<endl;
            if(itr->second.second==1){
                return itr->second.first; 
            }
        }
        return -1;
    }
};