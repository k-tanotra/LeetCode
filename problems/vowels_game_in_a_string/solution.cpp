class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        int v = 0;
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                v++;
            }
            else{
                c++;
            }
        }
        if(v==0){
            return false;
        }
        if(v%2==1){
            return true;
        }
        if(v>=2 && v%2==0){
            return true;
        }
        return false;
    }
};