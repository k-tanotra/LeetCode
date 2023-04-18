class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_set<string> m;
        for(int i=0;i<word.size();i++){
            for(int j=0;j<word.size();j++){
                m.insert(word.substr(i,j-i+1));
            }
        }
        int count = 0;
        for(int i=0;i<patterns.size();i++){
            if(m.find(patterns[i])!=m.end())
                count++;
        }
        return count;
    }
};