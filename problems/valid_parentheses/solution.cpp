class Solution {
public:
    bool isValid(string s) {
        vector<char> counter;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                counter.push_back(s[i]);
            }
            else if(s[i]==')'){
                if(counter.size()<=0 || counter.back()!='('){
                    return false;
                }
                counter.pop_back();
            }
            else if(s[i]=='}'){
                if(counter.size()<=0 || counter.back()!='{'){
                    return false;
                }
                counter.pop_back();
            }
            else if(s[i]==']'){
                if(counter.size()<=0 || counter.back()!='['){
                    return false;
                }
                counter.pop_back();
            }
        }
        return (counter.size()==0);
    }
};