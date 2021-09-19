class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,bool> m1;
        map<char,bool> m2;
        map<char,bool> m3;
        
        string row1 = "qwertyuiopQWERTYUIOP";
        string row2 = "asdfghjklASDFGHJKL";
        string row3 = "zxcvbnmZXCVBNM";
        
        for(int i=0;i<row1.length();i++){
            m1.insert({row1[i],true});
        }
        for(int i=0;i<row2.length();i++){
             m2.insert({row2[i],true});
        }
        for(int i=0;i<row3.length();i++){
             m3.insert({row3[i],true});
        }
        vector<string> res;
        bool b1,b2,b3;
        b1 = false;
        b2 = false;
        b3 = false;
        
        for(int i=0;i<words.size();i++){
            bool ans = true;
            b1 = false;
            b2 = false;
            b3 = false;
            for(int j=0;j<words[i].length();j++){
                if(m1.find(words[i][j])!=m1.end()){
                    b1 = true;
                    if(b2 || b3){
                        ans = false;
                        break;
                    }
                }
                else if(m2.find(words[i][j])!=m2.end()){
                    b2 = true;
                     if(b1 || b3){
                        ans = false;
                        break;
                    }
                }
                else if(m3.find(words[i][j])!=m3.end()){
                    b3 = true;
                     if(b2 || b1){
                        ans = false;
                        break;
                    }
                }
            }
            if(ans){
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
};