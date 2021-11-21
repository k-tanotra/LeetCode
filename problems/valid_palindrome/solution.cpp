class Solution {
public:
    string transform(string s){
        string ans;
        int i =0;
        while(s[i]!='\0'){
            if( (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans += s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                char c = s[i] - 'A' + 'a';
                ans += c;
            }
            i++;
        }
        return ans;
    }
    bool check(string s){
        int start = 0;
        int end = s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string st = transform(s);
        return check(st);
    }
};