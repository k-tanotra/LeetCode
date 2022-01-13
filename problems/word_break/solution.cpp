class Solution {
public:
    unordered_set<string> st;
    int n;
    bool rec(string s,int idx,vector<int> &dp){
        if(idx>=n){
            return true;
        }
        if(dp[idx]==-1){
            string temp = "";
            for(int i=idx;i<n;i++){
                temp +=s[i];
                if(st.find(temp)!=st.end() && rec(s,i+1,dp)){
                    dp[idx]=true;
                    break;
                }
            }
            if(dp[idx]==-1)
                dp[idx] = 0;
        }
        return dp[idx];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string s:wordDict){
            st.insert(s);
        }
        n = s.length();
        vector<int> dp(n,-1);
        return rec(s,0,dp);
    }
};