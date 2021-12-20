class Solution {
public:
    int magicalString(int n) {
        if(n==1 || n==2 || n==3){
            return 1;
        }
        string s ="122";
        bool flip = true; //1
        int start = 2;
        int count = 1;
        for(int i=start;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            if(flip){
                if(s[i]=='2'){
                    s += '1';
                    s += '1';
                }
                else{
                    s += '1';
                }
                flip = !flip;
            }
            else{
                if(s[i]=='2'){
                    s += '2';
                    s += '2';
                }
                else{
                    s += '2';
                }
                flip =!flip;
            }
        }
       return count; 
    }
};