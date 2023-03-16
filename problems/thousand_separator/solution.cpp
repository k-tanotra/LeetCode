class Solution {
public:
    string thousandSeparator(int n) {
        int place = 0;
        string ans = "";
        if(n==0){
            return "0";
        }
        while(n>0){
            int x = n%10;
            n = n/10;
            if(place==3){
                ans+=".";
                place = 0;
            }
            ans += to_string(x);
            place++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};