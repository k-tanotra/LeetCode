class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        int p = 1;
        while(num1>0 || num2>0 || num3){
            ans += p*min(num1%10,min(num2%10,num3%10));
            num1 = num1/10;
            num2 = num2/10;
            num3 = num3/10;
            p = p*10;
        }
        return ans;
    }
};