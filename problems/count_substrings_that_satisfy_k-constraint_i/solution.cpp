class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans  = 0;
        for(int i=0;i<s.size();i++){
            int ones = 0;
            int zeros= 0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='1'){
                    ones++;
                }
                else if(s[j]=='0'){
                    zeros++;
                }
                if(ones<=k || zeros<=k){
                    //cout<<i<<" "<<j<<"---"<<s[i]<<" "<<s[j]<<endl;
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        //cout<<endl;
        return ans;
    }
};