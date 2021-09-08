class Solution {
public:
    bool isValid(string s) {
        if(s.length()<2){
            return false;
        }
        stack<char> p;
        // cout<<p.empty()<<endl;
        p.push(s[0]);
        int i = 1;
        while(s[i]!='\0'){
            if(s[i]==')'){
                if(p.empty() || p.top()!='('){
                    return false;
                }
                p.pop();
            }
            else if(s[i]=='}'){
                if(p.empty() || p.top()!='{'){
                    return false;
                }
                p.pop();
            }
            else if(s[i]==']'){
                if(p.empty() || p.top()!='['){
                    return false;
                }
                p.pop();
            }
            else{
                p.push(s[i]);
            }
            i++;
        }
        
        if(!p.empty()){
            return false;
        }
        return true;
    }
};