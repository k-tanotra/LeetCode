class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0){
            ans.push_back(0);
            n--;
        }
        n=n/2;
        int start  = 1;
        while(n>0){
            ans.push_back(start);
            ans.push_back(-1*start);
            start++;
            n--;
        }
        return ans;
    }
};