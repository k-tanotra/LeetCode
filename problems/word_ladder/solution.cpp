class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(string s:wordList){
            st.insert(s);
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()){
            if(q.front().first==endWord){
                return q.front().second;
            }
            string temp = q.front().first;
            int count = q.front().second;
            q.pop();
            st.erase(temp);
            for(int i=0;i<temp.length();i++){
                char c = temp[i];
                for(int j=0;j<26;j++){
                    temp[i] = 'a' + j;
                    if(st.find(temp)!=st.end() && temp[i]!=c){
                        q.push({temp,count+1});
                    }
                }
                temp[i] = c;
            }
        }
        
        return 0;
    }
};