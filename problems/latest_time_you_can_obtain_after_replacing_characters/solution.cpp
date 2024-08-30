class Solution {
public:
    string findLatestTime(string s) {
        string t = s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                if(i==0){
                    if(s[i+1]=='?' || s[i+1]=='1' || s[i+1]=='0')
                        t[i] = '1';
                    else
                        t[i]='0';
                }
                else if(i==1){
                    if(t[i-1]=='0'){
                        t[i] = '9';
                    }
                    else{
                        t[i]= '1';
                    }
                }
                else if(i==3){
                    t[i]='5';
                }
                 else if(i==4){
                    t[i]='9';
                }
            }
        }
        return t;
    }
};