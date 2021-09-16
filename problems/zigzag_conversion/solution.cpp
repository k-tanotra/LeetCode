class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<int> > mat;
        if(numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            mat.push_back(temp);
        }
        string ans = "";
        int len = s.length();
        int mov = 0;
        bool flip = true;
        for(int i=0;i<len;i++){
            mat[mov].push_back(s[i]);
            if(flip){
                mov++;
                if(mov==numRows){
                    flip = false;
                    mov-=2;
                }
            }
            else{
                mov--;
                if(mov<0){
                    mov+=2;
                    flip = true;
                }
            }
        }
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j<mat[i].size();j++){
                ans += mat[i][j];
            }
        }
        return ans;
    }
};