class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t;i++){
            vector<long long> temp(26,0);
            for(int i=0;i<freq.size();i++){
                long long c = freq[i];
                if(i==freq.size()-1){
                    temp[0] += c;
                    temp[1] += c;
                    temp[0] = temp[0]%(1000000007);
                    temp[1] = temp[1]%(1000000007);
                }
                else{
                    temp[i+1] += c;
                    temp[i+1] = temp[i+1]%(1000000007);
                }
            }
            freq = temp;
        }
        long long l = 0;
        for(int i=0;i<freq.size();i++){
            l+= freq[i];
        }
        return l%(1000000007);
    }
};