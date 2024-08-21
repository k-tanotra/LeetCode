class Solution {
public:
    std::vector<int> sieveOfEratosthenes(int n) {
        std::vector<bool> isPrime(n, true); 
        std::vector<int> primes;  
        isPrime[0] = isPrime[1] = false; 
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i); 
                for (int j = i * 2; j < n; j += i) {
                    isPrime[j] = false; 
                }
            }
        }
        return primes;
    }

    int nonSpecialCount(int l, int r) {
        int lm = sqrt(r)+1;
        vector<int> primes = sieveOfEratosthenes(lm);
        int cnt = 0;
        for(int i=0;i<primes.size();i++){
           int x = primes[i]*primes[i];
           if(x>=l && x<=r){
               cnt++;
           }
        }
        return r-l+1 - cnt;
    }
};