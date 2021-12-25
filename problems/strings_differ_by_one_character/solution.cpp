class Solution {
public:
    bool differByOne(vector<string>& dict) {
        unordered_map<string,int> m;
        for(int i=0;i<dict.size();i++){
            m[dict[i]] = i;
        }
        
        for(int i=0;i<dict.size();i++){
            for(int j=0;j<dict[i].length();j++){
                char temp = dict[i][j];
                for(int k=0;k<26;k++){
                    dict[i][j] = 'a' + k;
                    //cout<<dict[i]<<endl;
                    if(m.find(dict[i])!=m.end() && dict[i][j]!=temp){
                        return true;
                    }
                }
                dict[i][j] = temp;
                //cout<<endl;
            }
        }
        
        return false;
    }
};