class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){
            return 0;
        }
        else if(n==0){
            return 1;
        }
        else if(x==1){
            return 1;
        }
        else if(x==-1){
            if(n%2==0){
                return 1;
            }
            return -1;
        }
        
        double ans = 1;
        if(n<0){
            while(n<0 && ans!=0){
                if(n%2==0){
                    x = x*x;
                    n = n/2;
                }
                else{
                    n=n+1;
                    ans = ans/x;
                }
            }
        }
        else{
            while(n>0 && ans!=0){
                if(n%2==0){
                    x = x*x;
                    n=n/2;
                }
                else{
                    n=n-1;
                    ans = ans*x;
                }
            }
        }
        
        return ans;
    }
};