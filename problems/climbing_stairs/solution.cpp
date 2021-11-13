class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n,0);
        // dp[0] = 1;
        // dp[1] = 2;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int a = 1;
        int b = 2;
        int c;
        for(int i=2;i<n;i++){
            c = b + a;
            a = b;
            b = c;
        }
        return c;
    }
};