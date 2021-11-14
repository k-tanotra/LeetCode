class Solution {
public:
    bool checksubset(map<char,int> &a, map<char,int> &b){
        if(a.size()!=b.size()){
            return false;
        }
        auto itr2 = a.begin();
        for(auto itr=b.begin();itr!=b.end();itr++){
            if(itr2->first!=itr->first){
                return false;
            }
            else if(itr2->second>itr->second){
                return false;
            }
            itr2++;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> m;
        map<char,int> tm;
        
        int len1 = s.length();
        int len2 = t.length();
        for(int i=0;i<len2;i++){
            m[t[i]]++;
        }
        
        int st = 0;
        int end = 0;
        int sz = INT_MAX;
        string ans = "";
        int prev = -1;
        
        while(end<len1){
            if(m.find(s[end])!=m.end() && (prev!=end)){
                 tm[s[end]]++;
            }
            prev = end;
            if(!checksubset(m,tm)){
                end++;
            }
            else{
                if(end-st+1<sz){
                    sz = end-st+1;
                    ans = s.substr(st,sz);
                }
                if(tm.find(s[st])!=tm.end()){
                    tm[s[st]]--;
                }
                st++;
            }
        }
        
        return ans;
    }
};