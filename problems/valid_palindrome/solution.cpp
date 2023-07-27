class Solution {
public:
    bool isAlphaNumeric(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            if(!isAlphaNumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphaNumeric(s[end])){
                end--;
                continue;
            }
            if(s[start]>='A' && s[start]<='Z'){
                s[start] = s[start] - 'A' + 'a';
            }
            if(s[end]>='A' && s[end]<='Z'){
                s[end] = s[end] - 'A' + 'a';
            }
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};