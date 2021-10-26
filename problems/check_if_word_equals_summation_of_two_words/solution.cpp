class Solution {
public:
    long long toNum(string s){
        long long ans = 0;
        int i=s.length()-1;
        long long ten = 1;
        while(i>=0){
            ans += ( s[i] - 'a' ) * ten;
            ten = ten * 10;
            i--;
        }
        
        return ans;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        if(toNum(firstWord) == (toNum(targetWord) - toNum(secondWord)) ){
            return true;
        }
        return false;
    }
};