class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i;
        int last=0;
        for(i=0;i<s.length();i+=k){
            if(i+k<=s.length()){
                ans.push_back(s.substr(i,k));
                last = i+k;
            }
        }
        //cout<<last<<" "<<s.length()<<endl;
        string t = "";
        if(last<s.length()){
            while(last<s.length()){
            t+=s[last];
            last++;
            }
            while(t.size()<k){
                t+= fill;
            }
        }
        if(t!=""){
            ans.push_back(t);
        }
        return ans;
    }
};