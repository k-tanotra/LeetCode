class Solution {
public:
    int findNthDigit(int n) {
        if(n>=1 && n<=9){
            return n;
        }
        int nines = 9;
        int digi = 1;
        int cur = 0;
        while(n/digi>nines){
            cur += nines;
            n -=nines*digi;
            nines = nines*10;
            digi++;
        }
        //cout<<n<<" "<<nines<<" "<<cur<<" "<<digi<<" "<<act<<" "<<rem<<endl;
        cur = cur+n/digi;
        if(n%digi==0){
            return cur%10;
        }
        
        cur=cur+1;
        string s = to_string(cur);
        return s[n%digi-1]-'0';
        
    }
};