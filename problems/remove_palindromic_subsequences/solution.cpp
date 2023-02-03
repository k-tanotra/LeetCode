class Solution {
public:
    bool isPalindrome(string s){
        int start = 0;
        int end = s.size()-1;
        while(start<=end && s[start]==s[end]){
            start++;
            end--;
        }
        return start>end;
    }
    int removePalindromeSub(string s) {
        if(s.size()==0){
            return 0;
        }
        if(isPalindrome(s)){
            return 1;
        }
        return 2;
    }
};