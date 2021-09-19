class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> freq(5,1);
        vector<int> m(5,0);
        m[0] = 1; m[1] = 2; m[2] = 4; m[3] = 2; m[4] = 1;
        if(n==1){
            return 5;
        }
        long long ans = 0;
        long long a = 0; long long e = 0; long long i = 0; long long o = 0; long long u = 0;
        for(int k=1;k<n;k++){
            a = 0; e = 0; i = 0; o = 0; u = 0;
            
            e += freq[0] %1000000007;
            a += freq[1] %1000000007;
            i += freq[1] %1000000007;
            a += freq[2] %1000000007;
            e += freq[2] %1000000007;
            o += freq[2] %1000000007;
            u += freq[2] %1000000007;
            i += freq[3] %1000000007;
            u += freq[3] %1000000007;
            a += freq[4] %1000000007;
            
            // cout<<a<<" "<<e<<" "<<i<<" "<<o<<" "<<u<<endl;
            freq[0] = a;
            freq[1] = e;
            freq[2] = i;
            freq[3] = o;
            freq[4] = u;
        }
        ans = (a+e+i+o+u)%1000000007;;
        return ans;
    }
};