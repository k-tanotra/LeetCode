class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        for(int i=0;i<s.size();i+=k){
            //cout<<"HH"<<" "<<i<<endl;
            int sum = 0;
            for(int j=i;j<i+k;j++){
                sum += s[j]-'a';
                //cout<<s[j]<<" "<<sum<<endl;
            }
            sum = sum%26;
            ans += 'a'+sum;
        }
        return ans;
    }
};