class Solution {
public:
    vector<string> customSplit(string path){
        string temp = "";
        vector<string> ans;
        for(int i=0;i<path.length();i++){
            
            if(path[i]=='/' && temp.empty()){
                continue;
            }
            else if(path[i]=='/' && !temp.empty()){
                if(temp==".."){
                    if(ans.size()>0){
                        ans.erase(ans.end() - 1);
                    }
                }
                else if(temp!="."){
                    ans.push_back(temp);
                }
                temp="";
            }
            else{
                temp += path[i];
            }
        }
        
        if(!temp.empty()){
            if(temp==".."){
                if(ans.size()>0){
                    ans.erase(ans.end() - 1);
                }
            }
            else if(temp!="."){
                ans.push_back(temp);
            }
            temp="";
        }
        return ans;
    }
    string simplifyPath(string path) {
        vector<string> v = customSplit(path);
        string ans = "/";
        for(int i=0;i<v.size();i++){
            ans += v[i] + "/";
        }
        if(ans.size()>0 && ans!="/"){
            ans.erase(ans.end() - 1);
        }
        return ans;
    }
};