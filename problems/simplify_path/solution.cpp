class Solution {
public:
    vector<string> split(string s){
        string temp = "";
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='/'){
                if(temp!="")
                    ans.push_back(temp);
                temp="";
            }
            else{
                temp +=s[i];
            }
        }
        if(temp!=""){
            ans.push_back(temp);
        }
        return ans;
    }
    void print(vector<string> r){
        for(int i=0;i<r.size();i++){
            cout<<r[i]<<" ";
        }
        cout<<endl;
    }
    string simplifyPath(string path) {
        vector<string> res = split(path);
        
       // print(res);
        stack<string> st;
        for(int i=0;i<res.size();i++){
            if(res[i]=="."){
                continue;
            }
            else if(res[i]==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(res[i]);
            }
            
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans=="")
            return "/";
        return ans;
    }
};