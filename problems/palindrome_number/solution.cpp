class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0){
        return false;
       }
       long num = 0;
       int num2 = x;
       int p = 0;
       while(num2>0){
        p++;
        num2=num2/10;
       }
       p--;
       //cout<<p<<endl;
       num2 = x;
       while(num2>0){
         num += pow(10,p)*(num2%10);
         p--;
         num2=num2/10;
       }
      // cout<<num<<endl;
       if(x==num){
        return true;
       }
       return false;
    }
};