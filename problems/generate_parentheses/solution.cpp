class Solution {
public:
    bool check(string s){
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                c++;
            }
            else if(s[i]==')'){
                c--;
            }
            if(c<0){
                return false;
            }
        }
        return (c==0);
    }
    void generate(string cur,vector<string> &res,int left,int right){
        if(left==0 && right==0){
            if(check(cur)){
                res.push_back(cur);
                return;
            }
        }

        if(left>0){
            generate(cur+'(',res,left-1,right);
        }
        if(right>0){
            generate(cur+')',res,left,right-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        vector<string> res;
        generate(cur,res,n,n);
        return res;
    }
};