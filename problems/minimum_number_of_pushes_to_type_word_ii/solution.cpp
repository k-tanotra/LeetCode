class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int pushes = 0;
        int x = 1;
        int p = 1;
        for(int i=0;i<freq.size();i++){
            if(x%9==0){
                x = 1;
                p++;
            }
            pushes += p*freq[i];
            x++;
        }
        return pushes;
    }
};