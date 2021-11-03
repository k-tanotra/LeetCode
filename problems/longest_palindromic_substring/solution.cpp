class Solution {
public:
    string longestPalindrome(string s) {
        //two solution manechars  algo
        
        //dp solution
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[0][i] = true;
        }
        
        int size = 1;
        int start = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(s[j]==s[j+i] &&  (i<2 || dp[i-2][j+1])){
                    dp[i][j] = true;
                    if(i+1>size){
                        size = i+1;
                        start = j;
                        // break;
                    }
                }
            }
        }
        
        string ans = s.substr(start,size);
        return ans;
    }
};