class Solution {
public:
    long calSquares(int n){
        long sum = 0;
        while(n>0){
            int x = n%10;
            sum += x*x;
            n=n/10;
            //cout<<n<<endl;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(1){
            //cout<<n<<endl;
            long sum = calSquares(n);
            //<<sum<<endl;
            if(s.find(sum)!=s.end()){
                return false;
            }
           // cout<<"**"<<endl;
            if(sum==1){
                //cout<<"TTS"<<endl;
                return true;
            }
            if(sum>INT_MAX){
                return false;
            }
            s.insert(sum);
            n = sum;
        }
        return false;
    }
};