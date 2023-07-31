class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_map<string,char> m2;
        string temp = "";
        int j = 0;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' ' || i==s.size()){
                if(j>=pattern.size()){
                    return false;
                }
                //cout<<temp<<endl;
                if(!temp.empty()){
                    if(m.find(pattern[j])!=m.end() && m2.find(temp)!=m2.end()){
                        if(m[pattern[j]]!=temp){
                            return false;
                        }
                        if(m2[temp]!=pattern[j]){
                            return false;
                        }
                    }
                    else if(m.find(pattern[j])!=m.end()){
                        return false;
                    }
                    else if(m2.find(temp)!=m2.end()){
                        return false;
                    }
                    else{
                        m[pattern[j]] = temp;
                        m2[temp] = pattern[j];
                    }
                    j++;
                }
                //cout<<m[temp]<<endl;
                temp = "";
            }
            else{
                temp+=s[i];
            }
        }
        if(j!=pattern.size()){
            return false;
        }
        return true;
    }
};