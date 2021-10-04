class Solution {
public:
    int dp[100][100];
    long long NCR(int n,int r){
        if(n<r || r<0){
            return 0;
        }
        if(n==1 || n==r || r==0){
            return 1;
        }
        if(dp[n][r]==-1){
            dp[n][r] = NCR(n-1,r) + NCR(n-1,r-1);
        }
        return dp[n][r];
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        int nH = destination[1];
        int nV = destination[0];
        memset(dp,-1,sizeof(dp));
        int total = nH+nV;
        string ans = "";
        while(total--){
            long long h_first = nH<=0? 1: NCR(nH+nV-1,nV);
            if(k>h_first){
                k=k-h_first;
                ans+= nV>0? 'V':'H';
                nV--;
            }
            else{
                ans+= nH>0? 'H':'V';
                nH--;
            }
        }
        return ans;
    }
};