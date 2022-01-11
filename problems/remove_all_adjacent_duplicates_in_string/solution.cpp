class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        if(s.length()==0){
            return ans;
        }
        ans += s[0];
        int last = 0;
        for(int i=1;i<s.length();i++){
            //cout<<ans<<" "<<last<<endl;
           if(last<0){
               ans = "";
               ans += s[i];
               last = 0;
           }
           else if(ans[last]==s[i]){
               last--;
           }
           else if(last+1<=ans.length()-1){
               ans[last+1] = s[i];
               last++;
           }
            else{
                ans+=s[i];
                last++;
            }
        }
        return ans.substr(0,last+1);
    }
};