class Solution {
public:
    vector<string> split(string s){
        string temp = "";
        vector<string> v;
        for(int i=0;i<s.length();i++){
            if(s[i]==','){
                v.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        if(temp.length()!=0){
            v.push_back(temp);
        }
        return v;
    }
    bool isValidSerialization(string preorder) {
        if(preorder.length()==1 && preorder[0]=='#'){
            return true;
        }
        vector<string> pre = split(preorder);
        //for(int i=0;i<pre.size)
        stack<pair<string,int>> s;
        if(pre[0]!="#")
            s.push({pre[0],2});
        for(int i=1;i<pre.size();i++){
            //cout<<preorder[i]<<endl;
            if(pre[i]=="#"){
                if(s.empty()){
                    return false;
                }
                s.top().second--;
                while(!s.empty() && s.top().second==0){
                    //cout<<s.top().first<<" "<<s.top().second<<endl;
                    s.pop();
                    if(!s.empty())
                        s.top().second--;
                }
                if(s.empty() && i!=pre.size()-1){
                    return false;
                }
            }
            else{
                s.push({pre[i],2});
            }
            
        }
        //cout<<"i AM OUY"<<endl;
    
        if(!s.empty()){
            return false;
        }
        return true;
    }
};