class Solution {
public:
    bool check(int start,int end,string s,int len){
        while(start<len && end>=0 && s[start]==s[end]){
            start++;
            end--;
        }
        
        if(start>end)
            return true;
        
        return false;
    }
    void rec(string s,int idx,int len,vector<vector<string>> &ans,vector<string> t,vector<vector<int>> &dp){
        if(idx>=len){
            ans.push_back(t);
            return;
        }
        for(int i=idx;i<len;i++){
            if((s[i]==s[idx]) && (i-idx <=2 || dp[idx+1][i-1])){
                dp[idx][i] = 1;
                t.push_back(s.substr(idx,i-idx+1));
                rec(s,i+1,len,ans,t,dp);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<string>> ans;
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i=0;i<len;i++){
            dp[i][i] = 1;
        }
        vector<string> st;
        rec(s,0,len,ans,st,dp);
        return ans;
    }
};