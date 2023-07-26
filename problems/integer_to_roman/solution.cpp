class Solution {
public:
    string intToRoman(int num) {
        vector<int> v = {1,4,5,
                        9,10,40,
                        50,90,100,
                        400,500,900,
                        1000};
        vector<string> s = {"I","IV","V",
                            "IX","X","XL",
                            "L","XC","C",
                            "CD","D","CM",
                            "M"};
        int idx = v.size()-1;
        string ans = "";
        while(num>0 && idx>=0){
            int x = num - v[idx];
            if(x>=0){
                ans += s[idx];
                num = num-v[idx];
            }
            else{
                idx--;
            }
        }
        return ans;
    }
};