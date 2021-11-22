class Solution {
public:
    set<string> m;
    map<pair<int,string>,int> mp;
    int check(string s,int idx,string ans,bool prev){
        if(idx>=s.length() && prev){
            return 1;
        }
        else if(idx>=s.length()){
            return 0;
            
        }
        ans += s[idx];
        if(m.find(ans)!=m.end()){
            string temp = "";
            if(mp.find({idx,ans})==mp.end()){
                mp.insert({make_pair(idx,ans),check(s,idx+1,temp,true) || check(s,idx+1,ans,false)});
            }
            return mp[{idx,ans}];
            // return  check(s,idx+1,temp,true) || check(s,idx+1,ans,false);
        }
        if(mp.find({idx,ans})==mp.end()){
            mp.insert({{idx,ans},check(s,idx+1,ans,false)});
        }
        return mp[{idx,ans}];
        // return check(s,idx+1,ans,false);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string ans = "";
        m.clear();
        int prev = false;
        for(int i=0;i<wordDict.size();i++){
            m.insert(wordDict[i]);
        }
        return check(s,0,ans,prev);
    }
};