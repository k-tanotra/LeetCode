class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> m;
        for(int i=0;i<bannedWords.size();i++){
            m[bannedWords[i]]++;
        }
        int cnt = 0;
        for(int i=0;i<message.size();i++){
            if(m.find(message[i])!=m.end()){
                cnt++;
            }
        }
        return cnt>=2;
    }
};