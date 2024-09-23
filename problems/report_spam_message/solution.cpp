class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int cnt = 0;
        unordered_set<string> s;
        for(int i=0;i<bannedWords.size();i++){
            s.insert(bannedWords[i]);
        } 

        for(int i=0;i<message.size();i++){
            if(s.find(message[i])!=s.end()){
                cnt++;
                //s.erase(message[i]);
            }
        }
        return cnt>=2;
    }
};