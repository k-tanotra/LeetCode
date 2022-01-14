class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> fromRight(n);
        int mx = INT_MIN;
        int idx= -1;
        for(int i=n-1;i>=0;i--){
            if(s[i]-'0'>mx){
                mx = s[i]-'0';
                idx = i;
            }
            fromRight[i] = idx;
        }
        for(int i=0;i<n;i++){
            if(s[i]<s[fromRight[i]]){
                swap(s[i],s[fromRight[i]]);
                break;
            }
        }
        
        return stoi(s);
    }
};