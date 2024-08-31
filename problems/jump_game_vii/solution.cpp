class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]!='0'){
            return false;
        }
        vector<int> dp(s.size(),0);
        int n = dp.size();
        int sum = 0;
        for(int i=0;i<dp.size();i++){
            sum += dp[i];
            if((i==0) || (sum>0 && s[i]=='0')){
                if(i+minJump<n){
                    dp[i+minJump] += 1;
                }
                if(i+maxJump+1<n){
                    dp[i+maxJump+1] += -1;
                }
            }
        }
        if(sum>0)
            return true;
        return false;
    }
    // 0   0   0   0   0   0
    // 1  -1   
};