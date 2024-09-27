class Solution {
public:
    vector<string> split(string path){
        vector<string> ans;
        string temp = "";
        for(int i=0;i<path.size();i++){
            if(path[i]=='/' && temp.size()>0){
                ans.push_back(temp);
                temp = "";
            }
            else if(path[i]!='/'){
                temp +=path[i];
            }
        }
        if(temp.size()>0){
            ans.push_back(temp);
        }
        return ans;
    }
    string simplifyPath(string path) {
        vector<string> s = split(path);
        vector<string> t = {""};
        for(int i=0;i<s.size();i++){
            if(s[i]=="."){
                continue;
            }
            else if(s[i]==".."){
                if(t.size()>=1)
                    t.pop_back();
            }
            else{
                t.push_back(s[i]);
            }
        }
        string ans = "";
        for(int i=0;i<t.size();i++){
            if(i!=t.size()-1)
                ans+= t[i] + "/";
            else
                ans+= t[i];
        }
        if(ans[0]!='/')
            ans = "/" + ans;
        return ans;
    }
};