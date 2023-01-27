class Solution {
public:
    vector<string> split(string s){
        vector<string> res;
        string temp = "";
        for(int i=0;i<=s.size();i++){
            if(s[i]==' ' || i==s.size()){
                if(!temp.empty()){
                    res.push_back(temp);
                }
                temp="";
            }
            else{
                temp += s[i];
            }
        }
        return res;
    }
    void print(vector<string> &st){
        for(int i=0;i<st.size();i++){
            cout<<st[i]<<endl;
        }
    }
    vector<string> printVertically(string s) {
        vector<string> st = split(s);
        print(st);
        int idx = 0;
        bool allEnd = false;
        vector<string> res;
        while(!allEnd){
            allEnd = true;
            string x = "";
            for(int i=0;i<st.size();i++){
                if(idx<st[i].size()){
                    allEnd = false;
                    x += st[i][idx];
                }
                else{
                    x += " ";
                }
            }
            idx++;
            while(!x.empty() && x.back()==' '){
                x.pop_back();
            }
            if(!x.empty())
                res.push_back(x);
        }
        return res;
    }
};