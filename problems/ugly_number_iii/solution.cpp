class Solution {
public:
    long long GCD(long long a,long long b){
        if(a==0)
            return b;
        return GCD(b%a,a);
    }
    long long LCM(long long a,long long b){
        return a*b/GCD(a,b);
    }
    long long count(long long num,int a,int b,int c){
        long long ans = 0;
        ans += num/a;
        ans += num/b;
        ans += num/c;
        ans -= num/LCM(a,b);
        ans -= num/LCM(a,c);
        ans -= num/LCM(b,c);
        ans += num/LCM(a,LCM(b,c));
        return ans;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1;
        long long high = 2e9;
        long long mid;
        long long ans;
        while(low<=high){
            mid = low + (high-low) / 2;
            long long p = count(mid,a,b,c);
            if(p>=n){
                ans = mid;
                high = mid-1;
            }
            else if(p<n)
                low = mid+1;
        }
        return ans;
    }
};