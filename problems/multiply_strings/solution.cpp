class Solution {
public:
    string add(string a, string b){
        string ans = "";
        int len1,len2;
        len1 = a.length()-1;
        len2 = b.length()-1;
        int carry = 0;
        while(len1>=0 && len2>=0){
            // cout<<len1<<len2<<endl;
            int x = a[len1] - '0';
            int y = b[len2] - '0';
            // cout<<a[len1]<<b[len2]<<endl;
            y = x + y + carry;
            carry = y/10;
            y = y%10;
            char c = '0' + y;
            // cout<<y;
            ans = ans + c;
            len1--;
            len2--;
        }
        while(len1>=0){
            int x = a[len1] - '0';
            x = x + carry;
            carry = x/10;
            x = x%10;
            char c = '0' + x;
            ans = ans + c;
            len1--;
        }
        while(len2>=0){
            int x = b[len2] - '0';
            x = x + carry;
            carry = x/10;
            x = x%10;
            char c = '0' + x;
            ans = ans + c;
            len2--;
        }
        while(carry){
            char c = '0' + carry;
            ans = ans + c;
            carry = 0;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if(num1[0]=='0' || num2[0]=='0'){
            return "0";
        }
        string ans = "";
        string temp = "";
        int carry = 0;
        char c;
        for(int i=len1-1;i>=0;i--){
            int k = len1-i-1;
            int a = num1[i] - '0';
            temp = "";
            for(int j=len2-1;j>=0;j--){
                int b = num2[j] - '0';
                b = a * b + carry;
                carry = b/10;
                b = b%10;
                c = b + '0';
                temp = temp + c;
            }
            if(carry){
                c = carry + '0';
                temp = temp + c;
                carry = 0;
            }
            reverse(temp.begin(),temp.end());
            while(k>0){
                temp = temp + '0';
                k--;
            }
            cout<<temp<<endl;
            ans = add(ans,temp);
        }
        
        return ans;
    }
};