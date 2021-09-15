class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int x = i*i + j*j;
                int y = sqrt(x);
                if(x==y*y && x<=n*n){
                        ans+=2;
                }
            }
        }
        return ans;
    }
};