class Solution {
public:
    vector<string> split(string s){
        string temp;
        vector<string> ans;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                temp += s[i];
            }
            else if(s[i]==' '){
                continue;
            }
            else{
                if(temp.length()!=0){
                    ans.push_back(temp);
                    temp="";
                }
                temp+=s[i];
                ans.push_back(temp);
                temp ="";
            }
        }
        if(temp.length()!=0){
            ans.push_back(temp);
        }
        return ans;
    }
    int calculate(string s) {
        vector<string> test = split(s);
        /*
        for(string t:test){
            cout<<t;
        }
        */
        vector<string> div;
        int last = -1;
        for(int i=0;i<test.size();i++){
            if(test[i]=="/"){
                int x = stoi(div[last]);
                int y = stoi(test[i+1]);
                div[last] = to_string(x/y);
                i=i+1;
            }
            else if(test[i]=="*"){
                int x = stoi(div[last]);
                int y = stoi(test[i+1]);
                div[last] = to_string(x*y);
                i=i+1;
            }
            else{
                last++;
                div.push_back(test[i]);
            }
        }
        /*
        for(string d:div){
            cout<<d<<" ";
        }*/
        
        int ans = stoi(div[0]);
        for(int i=1;i<div.size();i++){
            if(div[i]=="+"){
                ans+= stoi(div[i+1]);
                i = i+1;
            }
            else if(div[i]=="-"){
                ans-= stoi(div[i+1]);
                i = i+1;
            }
        }
        return ans;
    }
};