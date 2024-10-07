class Solution {
public:
    string removeLeadingZeros(string s){
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                idx++;
            }
            else{
                break;
            }
        }
        return s.substr(idx);
    }
    string toBinary(int num){
        string temp = "";
        while(num>0){
            if(num&1){
                temp = "1" + temp;
            }
            else{
                temp = "0" + temp;
            }
            num = num>>1;
        }
        temp = removeLeadingZeros(temp);
        return temp;
    }
    int binaryToInt(string s){
        int num = 0;
        int two = 1;
        for(int i=s.size()-1;i>=0;i--){
            num += two*(s[i]-'0');
            two*=2;
        }
        return num;
    }
    int maxGoodNumber(vector<int>& nums) {
        string num1 = toBinary(nums[0]);
        cout<<num1<<endl;
        string num2 = toBinary(nums[1]);
        cout<<num2<<endl;
        string num3 = toBinary(nums[2]);
        cout<<num3<<endl;
        int ans = -1;
        int t1 = binaryToInt(num1+num2+num3);
        cout<<t1<<endl;
        ans = max(ans,t1);
        int t2 = binaryToInt(num1+num3+num2);
        ans = max(ans,t2);
        int t3 = binaryToInt(num2+num1+num3);
        ans = max(ans,t3);
        int t4 = binaryToInt(num2+num3+num1);
        ans = max(ans,t4);
        int t5 = binaryToInt(num3+num1+num2);
        ans = max(ans,t5);
        int t6 = binaryToInt(num3+num2+num1);
        ans = max(ans,t6);
        cout<<max(t1,max(t2,max(t3,max(t4,max(t5,t6)))))<<endl;
        return ans;
    }
};