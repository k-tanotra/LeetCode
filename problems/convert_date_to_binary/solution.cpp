class Solution {
public:
    string bin(string temp){
        int n = stoi(temp);
        string res = "";
        while(n>0){
            if(n & 1){
                res += "1";
            }
            else{
                res += "0";
            }
            n = n/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string convertDateToBinary(string s) {
        string ans = "";
        string temp = "";
        for(int i=0;i<=s.size();i++){
            if(s[i]=='-' || i==s.size()){
                ans += bin(temp);
                if(i!=s.size())
                    ans += "-";
                temp="";
            }
            else{
                temp += s[i];
            }
        }
        return ans;
    }
};