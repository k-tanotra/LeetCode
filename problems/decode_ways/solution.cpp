class Solution {
public:
    bool check(char c){
        if(c>='A' && c<='Z'){
            return true;
        }
        else
            return false;
    }
    int numDecodings(string s) {
        
        int len = s.length();
        vector<int> dp(len+2,0);
        dp[0] = 1;
        dp[1] = 1;
        // for(int i=0;i<len+2;i++){
        //     cout<<dp[i]<<" ";
        // }
        for(int i=0;i<len;i++){
           
            if(i==0 && s[i]=='0'){
                return 0;
            }
            else if(i==0){
                dp[i+2] = dp[i+1];
            }
            else{
                char c1 = '$';
                char c2 = '$';
                int t1 = 0;
                int t2 = 0;
                int t3;
                t1 = s[i] - '0';
                t2 = s[i-1] - '0';
                if(t1!=0)
                    c1 = char('A' + t1 - 1);
                if(t2!=0)
                    c2 = char('A'-1 + t2*10 + t1);
                
                // cout<<endl;
                // cout<<c1<<" "<<c2<<endl;
                if(c1!='$' && check(c1)){
                    dp[i+2] += dp[i+1];
                }
                else{
                    c1='$';
                }
                
                if(c2!='$' && check(c2)){
                    dp[i+2] += dp[i];
                }
                else{
                   c2='$';
                }
                
                if(c1=='$' && c2=='$'){
                    return 0;
                }
            }
        }
        // for(int i=0;i<len+2;i++){
        //     cout<<dp[i]<<" ";
        // }
        return dp[len+1];
    }
};