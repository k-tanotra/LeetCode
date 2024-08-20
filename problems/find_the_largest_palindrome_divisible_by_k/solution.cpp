class Solution {
public:
    bool isDivisibleBy7(string& s) {
        int remainder = 0;
        for (char c : s) {
            remainder = (remainder * 10 + (c - '0')) % 7;
        }
        return remainder == 0;
    }
    string largestPalindrome(int n, int k) {
        string temp = "";
        for(int i=0;i<n;i++){
            temp += '9';
        }

        if(k==1 || k==3 || k==9){
            return temp;
        }
        else if(k==2){
            temp[0] = '8';
            temp[n-1] = '8';
            return temp;
        }
        else if(k==4){
            temp[0] = '8';
            temp[n-1] = '8';
            if(n>=3){
                temp[1] = '8';
                temp[n-2] = '8';
            }
        }
        else if(k==8){
            temp[0] = '8';
            temp[n-1] = '8';
            if(n>=3){
                temp[1] = '8';
                temp[n-2] = '8';
            }
            if(n>=5){
                temp[2] = '8';
                temp[n-3] = '8';
            }
        }
        else if(k==5){
            temp[0] = '5';
            temp[n-1] = '5';
        }
        else if(k==6){
            if(n==1){
                temp[0] = '6'; 
                return temp;
            }
            else if(n==2){
                temp = "66";
                return temp;
            }
            temp[0] = '8';
            temp[n-1] = '8';
            if(n%2==0){
                temp[n/2] = '7';
                temp[n/2 -1] = '7';
            }
            else{
                temp[n/2] = '8';
            }
        }
        else if(k==7){
            if(n%2==1){
                for(char i='9';i>='0';i--){
                    temp[n/2]=i;
                    if(isDivisibleBy7(temp)){
                        return temp;
                    }
                }
            }else{
                for(char i='9';i>='0';i--){
                    temp[n/2]=i;
                    temp[n/2-1]=i;
                    if(isDivisibleBy7(temp)){
                        return temp;
                    }
                }
            }
        }
        return temp;

    }
};
/*
89--98.  --- 2
88---88. --- 4
888---888 --- 8
*/