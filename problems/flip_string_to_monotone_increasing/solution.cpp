class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int sum = 0;
        for(int i=0;i<s.length();i++){
            sum += s[i]=='0'? 0:1;
        }
        int n = s.length()-1;
        int ans = sum;
        for(int i=n;i>=0;i--){
            if(s[i]=='0'){
                sum += 1;
            }
            else{
                sum-=1;
            }
            ans = min(ans,sum);
        }
        return ans;
    }
};