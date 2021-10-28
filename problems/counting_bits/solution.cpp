class Solution {
public:
    int setBits(int n){
        long x = 1;
        int count = 0;
        while(x<=n){
            count += (x&n)?1:0;
            x=x<<1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(setBits(i));
        }
        return ans;
    }
};