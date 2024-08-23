class Solution {
public:
    bool isSubstringPresent(string st) {
        unordered_set<string> s;
        string t = "";
        for(int i=0;i<st.size()-1;i++){
            t += st[i];
            t += st[i+1];
            s.insert(t);
            t = "";
        }
        for(int i=st.size()-1;i>=1;i--){
            t += st[i];
            t += st[i-1];
            if(s.find(t)!=s.end()){
                //cout<<t<<endl;
                return true;
            }
            t = "";
        }
        return false;
    }
};