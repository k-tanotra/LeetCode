class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        else if(x==0){
            return 0;
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
        
        //try2
        
        double ans = 1;
        long times = n;
        
        if(n<0){
            times = times*-1;
            while(times && ans!=0){
                if(times%2==0){
                    x = x*x;
                    times=times/2;
                }
                else{
                    ans=ans/x;
                    times=times-1;
                }
            }
        }
        else{
            while(times && ans!=0){
                if(times%2==0){
                    x = x*x;
                    times=times/2;
                }
                else{
                    ans=ans*x;
                    times=times-1;
                }
            }
        }
        /*
        if(n<0){
            times=times*-1;
            while(times && ans!=0){
                ans = ans/x;
                times--;
            }
        }
        else{
            while(times){
                ans = ans*x;
                times--;
            }
        }
        */
        return ans;
    }
};