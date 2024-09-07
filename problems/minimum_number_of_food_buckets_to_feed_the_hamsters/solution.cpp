class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='H'){
                bool sp1 = false;
                bool sp2 = false;
                if(i+1<n && s[i+1]=='.'){
                    sp2 = true;
                }
                if(i-1>=0 && s[i-1]=='.'){
                    sp1 = true;
                }
                if(i-1>=0 && s[i-1]=='*'){
                    continue;
                }
                if(!sp1 && !sp2){
                    return -1;
                }
                else if(sp1 && !sp2){
                    s[i-1] = '*';
                    ans++;
                }
                else{
                    s[i+1] = '*';
                    ans++;
                }
            }
        }
        return ans;
    }
};