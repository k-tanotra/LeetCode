class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        int c = 0;
        string ans = "";
        string fin = "";
        for(char ch:s){
            if(ch != '-') fin += toupper(ch);
        }
        //cout<<fin<<endl;
        for(int i=fin.size()-1;i>=0;i--){
            ans += fin[i];
            c++;
            if(c==k && i!=0){
                c=0;
                ans += '-';
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};