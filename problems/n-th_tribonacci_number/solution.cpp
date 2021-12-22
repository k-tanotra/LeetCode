class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1 || n==2){
            return 1;
        }
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i=3;i<=n;i++){
            int t1 = c;
            int t2 = b;
            c += a+b;
            b = t1;
            a = t2;
        }
        return c;
    }
};