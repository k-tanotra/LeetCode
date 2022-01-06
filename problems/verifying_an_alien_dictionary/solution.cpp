class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=0;i<order.size();i++){
            m[order[i]] = i;
        }
        for(int i=0;i<words.size()-1;i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int start = 0;
            while(start<word1.length() && start<word2.length() && word1[start]==word2[start]){
                start++;
            }
            if(start<word1.length() && start>=word2.length()){
                //cout<<"here"<<endl;
                return false;
            }
            else if(start<word1.length() && start<word2.length() && m[word1[start]]>m[word2[start]]){
                //cout<<"here 2"<<endl;
                return false;
            }
        }
        
        return true;
    }
};