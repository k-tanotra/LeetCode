class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry>0){
            int tot = carry;
            if(i>=0){
                tot += num1[i]-'0';
                i--;
            }
            if(j>=0){
                tot += num2[j]-'0';
                j--;
            }
            ans += char(tot%10 + '0');
            carry = tot/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};