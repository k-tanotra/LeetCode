class Solution {
public:
    string convertToBase7(int num) {
        int n =  0;
        if(num==0){
            return "0";
        }
        bool neg = false;
        if(num<0){
            neg = true;
        }
        num = abs(num);
        while(pow(7,n)<=num){
            n++;
        }
        n=n-1;
        
        string ans = "";
        
        while(n>=0){
            int m = pow(7,n);
            int x = num/m;
            num = num % m;
            n--;
            ans += to_string(x);
        }
        if(neg){
            return "-"+ans;
        }
        return ans;
    }
};