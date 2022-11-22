class Solution {
public:
    bool is(char c){
        if(c>='a' && c<='z'){
            return true;
        }
        return false;
    }
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText==""){
            return "";
        }
        int col = encodedText.size()/rows;
        string ans = "";
        int c = 0;
        while(c<col){
            int r = 0;
            int c2 = c;
            while(r<rows && c2<col){
                ans += encodedText[col*r+c2];
                r++;
                c2++;
            }
            c++;
        }
        int lastIdx = ans.size()-1;
        while(!is(ans[lastIdx])){
            lastIdx--;
        }
        ans = ans.substr(0,lastIdx+1);
        return ans;
    }
};