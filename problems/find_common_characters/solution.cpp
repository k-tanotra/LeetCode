class Solution {
public:
    void print(vector<int> &v){
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26,0);
        vector<int> freqFinal(26,0);
        for(int i=0;i<words.size();i++){
            vector<int> freq(26,0);
            for(int j=0;j<words[i].size();j++){
                freq[words[i][j]-'a']++;
            }
            if(i==0){
                freqFinal = freq;
                continue;
            }
            for(int i=0;i<26;i++){
                if(freq[i]>0 && freqFinal[i]>0){
                    freqFinal[i] = min(freqFinal[i],freq[i]);
                }
                else{
                    freqFinal[i] = 0;
                }
            }
        }
        vector<string> res;
        for(int i=0;i<26;i++){
            if(freqFinal[i]>0){
                string x = "";
                x+=(char)(i+'a');
                while(freqFinal[i]>0){
                    res.push_back(x);
                    freqFinal[i]--;
                }
            }
                
        }

        return res;
    }
};