class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
        vector<int> vec(n+1,0);
        vec[0]=0;
        vec[1]=1;
        int ans = 1;
        for(int i=1;i<(n+1)/2;i++){
            vec[2*i] = vec[i];
            vec[2*i+1] = vec[i] + vec[i+1];
            ans = max(ans,max(vec[2*i],vec[2*i+1]));
        }
        return ans;
    }
};