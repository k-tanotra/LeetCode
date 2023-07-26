class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        int i = n;
        while(s[i]==' '){
            i--;
        }
        int len = 0;
        while(i>=0 && s[i]!=' '){
            len++;
            i--;
        }
        return len;
    }
};