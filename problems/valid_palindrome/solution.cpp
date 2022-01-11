class Solution {
public:
    int isAlphaNum(char c){
        if(c>='a' && c<='z'){
            return 1;
        }
        if(c>='A' && c<='Z'){
            return 2;
        }
        if(c>='0' && c<='9'){
            return 3;
        }
        return 0;
    }
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        while(start<=end){
            int x = isAlphaNum(s[start]);
            int y = isAlphaNum(s[end]);
            if(x && y){
                if(x==2)
                    s[start] = 'a' + (s[start]-'A');
                if(y==2)
                    s[end] = 'a' + (s[end]-'A');
                
                if(s[start]!=s[end])
                    return false;
                start++;
                end--;
            }
            else if(!x){
                start++;
            }
            else if(!y){
                end--;
            }
        }
        
        return true;
    }
};