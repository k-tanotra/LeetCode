class Solution {
public:
    bool isPrefixSuffix(string a,string b){
        if(a.size()>b.size()){
            return false;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                //cout<<a<<" "<<b<<endl;
                return false;
            }
        }
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[b.size()-i-1]){
                //cout<<a<<" "<<b<<" "<<i<<endl;
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(isPrefixSuffix(words[i],words[j]))
                    count++;
            }
        }
        return count;
    }
};