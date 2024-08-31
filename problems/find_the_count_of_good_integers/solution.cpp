class Solution {
public:
    void getAll(int n,int k,unordered_set<string> &s){
        vector<long long> p;
        if(n==1){
            for(int i=0;i<10;i++){
                if(i%k==0){
                    s.insert(to_string(i));
                }
            }
        }
        int halfLength = (n + 1) / 2;
        int start = 1;
        int end = 1;
        for (int i = 1; i < halfLength; ++i) {
            start *= 10;
        }
        end = start * 10;
        for(int i=start;i<end;i++){
            string f = to_string(i);
            string q = f;
            if(n%2!=0){
                q += string(f.rbegin() + 1, f.rend());
            }
            else{
                q += string(f.rbegin(), f.rend());
            }
            long long x = stoll(q);
            if(x%k==0){
                sort(q.begin(),q.end());
                s.insert(q);
            }
        }
        
    }
    void print(vector<long long> &num){
        for(int n:num){
            cout<<n<<" ";
        }
        cout<<endl;
    }
    void print(unordered_set<string> &s){
        for(auto itr=s.begin();itr!=s.end();itr++){
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    
    long long cal(string s){
        int n = s.length();
        std::map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        long long total_permutations = factorial(n);
        for (auto& [digit, count] : freq) {
            total_permutations /= factorial(count);
        }
        if (freq['0'] == 0) {
            return total_permutations;
        }
        long long invalid_permutations = 0;
        freq['0']--;

        long long remaining_permutations = factorial(n - 1);
        for (auto& [digit, count] : freq) {
            remaining_permutations /= factorial(count);
        }
        invalid_permutations = remaining_permutations;
        return total_permutations - invalid_permutations;
    }
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> s;
        getAll(n,k,s);
        //print(p);
        //print(s);
        long long ans = 0;
        for(auto itr=s.begin();itr!=s.end();itr++){
            ans += cal(*itr);
        }
        return ans;
    }
};