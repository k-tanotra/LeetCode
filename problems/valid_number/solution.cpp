class Solution {
public:
    bool isNumber(string s) {
        bool eFound = false;
        bool dFound = false;
        bool numFound = false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='+' || s[i]=='-'){
                if(!(i==0 || (i>1 && (s[i-1]=='e' || s[i-1]=='E')) && i+1<s.length() && s[i+1]>='0' && s[i+1]<='9'))
                    return false;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if( !( !eFound && ((i>0 && i+1<s.length()) && ( (s[i+1]>='0' && s[i+1]<='9') || s[i+1]=='+' || s[i+1]=='-') && ((s[i-1]>='0' && s[i-1]<='9') || (s[i-1]=='.' && i-2>=0 && s[i-2]>='0' && s[i-2]<='9') )))){
                    return false;
                }
                eFound = true;
            }
            else if(s[i]=='.'){
               if( !( !dFound && !eFound && s.length()>1) ){
                    return false;
                }
                //cout<<s.length();
                dFound = true;
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                return false;
            }
            else if(s[i]>='0' && s[i]<='9'){
                numFound = true;
            }
        }
        
        return numFound;
    }
};