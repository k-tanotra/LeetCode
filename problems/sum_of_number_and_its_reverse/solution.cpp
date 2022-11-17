class Solution {
public:
    int getRevNumber(int num){
        int ans = 0;
        while(num>0){
            ans = ans*10 + num%10;
            num=num/10;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        //cout<<getRevNumber(140)<<endl;
        for(int i=0;i<=num;i++){
            if(i + getRevNumber(i) == num){
                return true;
            }
        }
        return false;
    }
};