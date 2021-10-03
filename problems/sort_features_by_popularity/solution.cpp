class Solution {
public:
    static bool cmp(pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
        if(a.second.first>b.second.first){
             return true;
        }
        else if(a.second.first==b.second.first){
            if(a.second.second<b.second.second)
                return true;
            else
                return false;
        }
        return false;
    }
    vector<string> split(string s,char delimiter){
        string ans = "";
        vector<string> res;
        for(int i=0;i<s.length();i++){
            if(s[i]==delimiter || s[i+1]=='\0'){
                if(s[i+1]=='\0' && s[i]!=delimiter)
                    ans = ans+s[i];
                if(ans.size()!=0)
                    res.push_back(ans);
                ans = "";
                continue;
            }
            ans = ans + s[i];
        }
        
        return res;
    }
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string,pair<int,int>> m1;
        for(int i=0;i<features.size();i++){
            m1.insert({features[i],{0,i}});
        }
        
        vector<string> res;
        
        for(int i=0;i<responses.size();i++){
            vector<string> t;
            vector<string> found;
            t = split(responses[i],' ');
            for(int j=0;j<t.size();j++){
                if(m1.find(t[j])!=m1.end() && m1[t[j]].first>=0){
                    m1[t[j]].first++;
                    m1[t[j]].first = m1[t[j]].first * -1;
                    found.push_back(t[j]);
                }
            }
            for(int j=0;j<found.size();j++){
                if(m1[found[j]].first<0){
                   m1[found[j]].first = m1[found[j]].first * -1;
                }
            }
        }
        
        vector<pair<string,pair<int,int> > >v;
        for(auto itr=m1.begin();itr!=m1.end();itr++){
            v.push_back({itr->first,{itr->second.first,itr->second.second}});
            // cout<<itr->first<<" "<<itr->second.first<<" "<<itr->second.second<<endl;
        }
        
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            res.push_back(v[i].first);
        }
        return res;
        
    }
};