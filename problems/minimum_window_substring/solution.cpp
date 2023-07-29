class Solution {
public:
    int getIdx(char c){
        if(c>='a' && c<='z'){
            return c-'a';
        }
        return c-'A'+26;
    }
    bool check(vector<int> &f,vector<int> &c){
        for(int i=0;i<f.size();i++){
            if(c[i]<f[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> freq(52,0);
        vector<int> com(52,0);
        for(int i=0;i<t.size();i++){
            freq[getIdx(t[i])]++;
        }
        int start = 0;
        int end = 0;
        int mnLen = INT_MAX;
        int startIdx;
        int prev = -1;
        while(start<s.size() && end<s.size()){
            //cout<<"*******"<<endl;
            //cout<<start<<" "<<s[start]<<endl;
            //cout<<end<<" "<<s[end]<<endl;
            if(freq[getIdx(s[end])]>0 && prev!=end){
                com[getIdx(s[end])]++;
                prev = end;
            }
            if(!check(freq,com)){
                end++;
            }
            else{
                //cout<<"FOUND"<<endl;
                if(end-start+1<mnLen){
                    mnLen = min(mnLen,end-start+1);
                    startIdx = start;
                }
                if(com[getIdx(s[start])]>0){
                    //cout<<com[getIdx(s[start])]<<endl;
                    //cout<<s[start]<<endl;
                    com[getIdx(s[start])]--;
                    //cout<<"^^^"<<endl;
                    //cout<<com[getIdx(s[start])]<<endl;
                    //cout<<s[start]<<endl;
                }
                start++;
                if(start>end){
                    end = start;
                }
            }
        }

        if(mnLen==INT_MAX)
            return "";
        return s.substr(startIdx,mnLen);
    }
};