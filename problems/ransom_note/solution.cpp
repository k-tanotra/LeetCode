class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<ransomNote.size();i++){
            freq1[ransomNote[i]-'a']++;
        }
        for(int i=0;i<magazine.size();i++){
            freq2[magazine[i]-'a']++;
        }

        for(int i=0;i<freq1.size();i++){
            if(freq1[i]>freq2[i]){
                return false;
            }
        }
        return true;
    }
};