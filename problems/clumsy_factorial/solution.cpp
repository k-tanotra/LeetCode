class Solution {
public:
    int fact(int n,bool f){
        if(f){
             return (n*(n-1))/(n-2) + (n-3);
        }
        else{
            return (n*(n-1))/(n-2) - (n-3);
        }
    }
    int c_fact(int n){
        int ans = fact(n,true);
        n=n-4;
        while(n>=4){
            ans-=fact(n,false);
            // cout<<n<<"--"<<fact(n,false);
            n=n-4;
        }
        if(n==1){
            return ans-1;
        }
        else if(n==2){
            return ans-2;
        }
        else if(n==3){
            return ans-6;
        }
        return ans;
    }
    int clumsy(int n) {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else if(n==3){
            return 6;
        }
        return c_fact(n);
    }
};