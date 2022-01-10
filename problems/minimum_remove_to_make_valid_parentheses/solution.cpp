class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
                if(count<0){
                    s[i] = '*';
                    count=0;
                }
            }
        }
        
        count =0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                count++;
            }
            else if(s[i]=='('){
                count--;
                if(count<0){
                    s[i]='*';
                    count=0;
                }
            }
        }
        
        for(int i=0;i<s.length();i++){
            if(s[i]!='*')
                ans+=s[i];
        }
        
        return ans;
    }
};