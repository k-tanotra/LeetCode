class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                if(m.find(words[i][j])==m.end()){
                    m.insert({words[i][j],1});
                }
                else{
                    m[words[i][j]]++;
                }
            }
        }
        int len = words.size();
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr->second%len !=0){
                return false;
            }
        }
        
        return true;
    }
};