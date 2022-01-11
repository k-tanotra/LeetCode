class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        //vector<int> fromLeft(n);
        vector<int> fromRight(n);
        /*
        int mn = INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++){
            if(s[i]-'0'<mn){
                mn = s[i]-'0';
                idx = i;
            }
            fromLeft[i] = idx;
        }*/
        int mx = INT_MIN;
        int idx= -1;
        for(int i=n-1;i>=0;i--){
            if(s[i]-'0'>mx){
                mx = s[i]-'0';
                idx = i;
            }
            fromRight[i] = idx;
        }
        
        int mn = INT_MAX;
        idx = -1;
        for(int i=0;i<n;i++){
            if(s[i]-'0'<mn){
                mn = s[i]-'0';
                idx = i;
            }
            if(s[idx]<s[fromRight[i]]){
                swap(s[idx],s[fromRight[i]]);
                break;
            }
        }
        
        return stoi(s);
    }
};